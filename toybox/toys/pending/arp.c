/* arp.c - manipulate the system ARP cache
 *
 * Copyright 2014 Sandeep Sharma <sandeep.jack2756@gmail.com>
 * Copyright 2014 Kyungwan Han <asura321@gamil.com>
 * No Standard 

USE_ARP(NEWTOY(arp, "vi:nDsdap:A:H:[+Ap][!sd]", TOYFLAG_USR|TOYFLAG_BIN))

config ARP
  bool "arp"
  default n
  help
    Usage: arp 
    [-vn] [-H HWTYPE] [-i IF] -a [HOSTNAME]
    [-v]              [-i IF] -d HOSTNAME [pub]
    [-v]  [-H HWTYPE] [-i IF] -s HOSTNAME HWADDR [temp]
    [-v]  [-H HWTYPE] [-i IF] -s HOSTNAME HWADDR [netmask MASK] pub
    [-v]  [-H HWTYPE] [-i IF] -Ds HOSTNAME IFACE [netmask MASK] pub

    Manipulate ARP cache

    -a    Display (all) hosts
    -s    Set new ARP entry
    -d    Delete a specified entry
    -v    Verbose
    -n    Don't resolve names
    -i IF Network interface
    -D    Read <hwaddr> from given device
    -A,-p AF  Protocol family
    -H    HWTYPE Hardware address type

*/

#define FOR_arp
#include "toys.h"
#include <net/if_arp.h>

GLOBALS(
    char *hw_type;
    char *af_type_A;
    char *af_type_p;
    char *interface;
    
    int sockfd;
    char *device;
)

struct arpreq req; //Global request structure 

struct type {
  char *name;
  int val;
};

struct type hwtype[] = {
  {"ether", ARPHRD_ETHER }, 
  {"loop" ,ARPHRD_LOOPBACK},
  {"ppp" ,ARPHRD_PPP},
  {"infiniband" ,ARPHRD_INFINIBAND},
  {NULL, -1},
};

struct type aftype[] = {
  {"inet", AF_INET }, 
  {"inet6" ,AF_INET6},
  {"unspec" ,AF_UNSPEC},
  {NULL, -1},
};

struct type flag_type[] = {
  {"PERM", ATF_PERM }, 
  {"PUB" ,ATF_PUBL},
  {"DONTPUB" ,ATF_DONTPUB},
  {"TRAIL" ,ATF_USETRAILERS},
  {NULL, -1},
};

static int get_index(struct type arr[], char *name)
{
  int i;
  
  for (i = 0; arr[i].name; i++) 
    if (!strcmp(arr[i].name, name)) break;
  return arr[i].val;
}


void get_hw_add(char *hw_addr, char *ptr) 
{
  char *p = ptr, *hw = hw_addr;

  while (*hw_addr && (p-ptr) < 6) {
    int val, len = 0;

    if (*hw_addr == ':') hw_addr++;
    sscanf(hw_addr, "%2x%n", &val, &len);
    if (!len || len > 2) break;
    hw_addr += len;
    *p++ = val;
  }

  if ((p-ptr) != 6 || *hw_addr)
    error_exit("bad hw addr '%s'", hw);
}

static void resolve_host(char *host, struct sockaddr *sa)
{
  struct addrinfo hints, *res = NULL;
  int ret;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  if ((ret = getaddrinfo(host, NULL, &hints, &res))) 
    perror_exit("%s", gai_strerror(ret));

  memcpy(sa, res->ai_addr, res->ai_addrlen);
  freeaddrinfo(res);
}

static void check_flags(int *i, char** argv)
{
  struct sockaddr sa;
  int flag = *i, j;
  struct flags {
    char *name;
    int or, flag;
  } f[] = {
    {"pub",  1 ,ATF_PUBL},
    {"priv", 0 ,~ATF_PUBL},
    {"trail", 1, ATF_USETRAILERS},
    {"temp", 0, ~ATF_PERM},
    {"dontpub",1, ATF_DONTPUB},
  };
  
  for (;*argv; argv++) {
    for (j = 0;  j < ARRAY_LEN(f); j++) { 
      if (!strcmp(*argv, f[j].name)) {
        (f[j].or) ?(flag |= f[j].flag):(flag &= f[j].flag);
        break;
      }
    }
    if (j > 4 && !strcmp(*argv, "netmask")) {
      if (!*++argv) error_exit("NULL netmask");
      if (strcmp(*argv, "255.255.255.255")) {
        resolve_host(toys.optargs[0], &sa);
        memcpy(&req.arp_netmask, &sa, sizeof(sa));
        flag |= ATF_NETMASK;
      } else argv++; 
    } else if (j > 4 && !strcmp(*argv, "dev")) {
      if (!*++argv) error_exit("NULL dev");
      TT.device = *argv;
    } else if (j > 4) error_exit("invalid arg");
  }
  *i = flag;
}

static int set_entry(void) 
{
  int flags = 0;
  
  if (!toys.optargs[1]) error_exit("bad syntax");

  if (!(toys.optflags & FLAG_D)) get_hw_add(toys.optargs[1], (char*)&req.arp_ha.sa_data);
  else {
    struct ifreq ifre;

    xstrncpy(ifre.ifr_name, toys.optargs[1], IFNAMSIZ);
    xioctl(TT.sockfd, SIOCGIFHWADDR, &ifre);
    if ((toys.optflags & FLAG_H) && (ifre.ifr_hwaddr.sa_family != ARPHRD_ETHER)) 
      error_exit("protocol type mismatch");
    memcpy(&req.arp_ha, &(ifre.ifr_hwaddr), sizeof(req.arp_ha));
  }

  flags = ATF_PERM | ATF_COM;
  if (toys.optargs[2]) check_flags(&flags, (toys.optargs+2));
  req.arp_flags = flags;
  xstrncpy(req.arp_dev, TT.device, sizeof(req.arp_dev));
  xioctl(TT.sockfd, SIOCSARP, &req);
  
  if (toys.optflags & FLAG_v) xprintf("Entry set for %s\n", toys.optargs[0]);
  return 0;
}

static int ip_to_host(struct sockaddr *sa, int flag) 
{
  int status = 0;
  char hbuf[NI_MAXHOST] = {0,}, sbuf[NI_MAXSERV] = {0,}; 
  socklen_t len = sizeof(struct sockaddr_in6);
  
  *toybuf = 0;
  if (!(status = getnameinfo(sa, len, hbuf, sizeof(hbuf), sbuf, 
          sizeof(sbuf), flag))) {
    strcpy(toybuf, hbuf);
    return 0;
  }
  return 1;
}

static int delete_entry(void)
{
  int flags;
  
  flags = ATF_PERM;
  if (toys.optargs[1]) check_flags(&flags, (toys.optargs+1));
  req.arp_flags = flags;
  xstrncpy(req.arp_dev, TT.device, sizeof(req.arp_dev));
  xioctl(TT.sockfd, SIOCDARP, &req);
  
  if (toys.optflags & FLAG_v) xprintf("Delete entry for  %s\n", toys.optargs[0]);
  return 0;
}

void arp_main(void)
{
  struct sockaddr sa;
  char ip[128], hw_addr[128], mask[12], dev[128], *host_ip = NULL, *buf;
  int h_type, type, flag, i, fd, entries = 0, disp = 0;

  TT.device = "";
  memset(&sa, 0, sizeof(sa));
  memset(&req, 0, sizeof(req));
  TT.sockfd = xsocket(AF_INET, SOCK_STREAM, 0);

  if ((toys.optflags & FLAG_A) || (toys.optflags & FLAG_p)) {
    if ((type = get_index(aftype, 
            (TT.af_type_A)?TT.af_type_A:TT.af_type_p)) != AF_INET) 
      error_exit((type != -1)?"only inet supported by kernel":"unknown family");
  } 

  req.arp_ha.sa_family = ARPHRD_ETHER;
  if (toys.optflags & FLAG_H) {
    if ((type = get_index(hwtype, TT.hw_type)) != ARPHRD_ETHER) 
      error_exit((type != -1)?"h/w type not supported":"unknown h/w type");
    req.arp_ha.sa_family = type;
  }

  if (((toys.optflags & FLAG_s) || toys.optflags & FLAG_d)) { 
    if (!toys.optargs[0]) error_exit("host name req");
    resolve_host(toys.optargs[0], &sa);
    memcpy(&req.arp_pa, &sa, sizeof(struct sockaddr));
  }

  if ((toys.optflags & FLAG_s) && !set_entry()) return;
  if ((toys.optflags & FLAG_d) && !delete_entry()) return; 

  //show arp chache
  fd = xopen("/proc/net/arp", O_RDONLY);
  buf = get_line(fd);
  free(buf); //skip first line

  if (toys.optargs[0]) {
    resolve_host(toys.optargs[0], &sa);
    ip_to_host(&sa, NI_NUMERICHOST);
    host_ip = xstrdup(toybuf);
  }

  while ((buf = get_line(fd))) {
    char *host_name = "?";
    
    if ((sscanf(buf, "%s 0x%x 0x%x %s %s %s\n", ip,
        &h_type, &flag, hw_addr, mask, dev )) != 6) break;
    entries++;
    if (((toys.optflags & FLAG_H) && (get_index(hwtype, TT.hw_type) != h_type))
     || ((toys.optflags & FLAG_i) && strcmp(TT.interface, dev))
     || (toys.optargs[0] && strcmp(host_ip, ip))) {
      free(buf);
      continue;
    }

    resolve_host(buf, &sa);
    if (!(toys.optflags & FLAG_n)) { 
      if (!ip_to_host(&sa, NI_NAMEREQD)) host_name = toybuf;
    } else ip_to_host(&sa, NI_NUMERICHOST);
    
    disp++;
    printf("%s (%s) at" , host_name, ip);

    for (i = 0; hwtype[i].name; i++) 
      if (hwtype[i].val & h_type) break;
    if (!hwtype[i].name) error_exit("unknown h/w type");

    if (!(flag & ATF_COM)) {
      if ((flag & ATF_PUBL)) printf(" *");
      else printf(" <incomplete>");
    } else printf(" %s [%s]", hw_addr, hwtype[i].name);

    if (flag & ATF_NETMASK) printf("netmask %s ", mask);

    for (i = 0; flag_type[i].name; i++) 
      if (flag_type[i].val & flag) printf(" %s", flag_type[i].name);

    printf(" on %s\n", dev);
    free(buf);
  }
  
  if (toys.optflags & FLAG_v) 
    xprintf("Entries: %d\tSkipped: %d\tFound: %d\n",
        entries, entries - disp, disp);
  if (!disp) xprintf("No Match found in %d entries\n", entries);
  
  if (CFG_TOYBOX_FREE) {
    free(host_ip);
    free(buf);
    xclose(fd);
  }
}
