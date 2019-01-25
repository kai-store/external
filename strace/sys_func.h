extern SYS_FUNC(accept);
extern SYS_FUNC(accept4);
extern SYS_FUNC(access);
extern SYS_FUNC(add_key);
extern SYS_FUNC(adjtime);
extern SYS_FUNC(adjtimex);
extern SYS_FUNC(arch_prctl);
extern SYS_FUNC(bind);
extern SYS_FUNC(brk);
extern SYS_FUNC(cacheflush);
extern SYS_FUNC(capget);
extern SYS_FUNC(capset);
extern SYS_FUNC(chdir);
extern SYS_FUNC(chmod);
extern SYS_FUNC(chown);
extern SYS_FUNC(clock_adjtime);
extern SYS_FUNC(clock_gettime);
extern SYS_FUNC(clock_nanosleep);
extern SYS_FUNC(clock_settime);
extern SYS_FUNC(clone);
extern SYS_FUNC(close);
extern SYS_FUNC(connect);
extern SYS_FUNC(creat);
extern SYS_FUNC(create_module);
extern SYS_FUNC(delete_module);
extern SYS_FUNC(dup);
extern SYS_FUNC(dup2);
extern SYS_FUNC(dup3);
extern SYS_FUNC(epoll_create);
extern SYS_FUNC(epoll_create1);
extern SYS_FUNC(epoll_ctl);
extern SYS_FUNC(epoll_pwait);
extern SYS_FUNC(epoll_wait);
extern SYS_FUNC(eventfd);
extern SYS_FUNC(eventfd2);
extern SYS_FUNC(execv);
extern SYS_FUNC(execve);
extern SYS_FUNC(exit);
extern SYS_FUNC(faccessat);
extern SYS_FUNC(fadvise64);
extern SYS_FUNC(fadvise64_64);
extern SYS_FUNC(fallocate);
extern SYS_FUNC(fanotify_init);
extern SYS_FUNC(fanotify_mark);
extern SYS_FUNC(fchmod);
extern SYS_FUNC(fchmodat);
extern SYS_FUNC(fchown);
extern SYS_FUNC(fchownat);
extern SYS_FUNC(fcntl);
extern SYS_FUNC(fgetxattr);
extern SYS_FUNC(finit_module);
extern SYS_FUNC(flistxattr);
extern SYS_FUNC(flock);
extern SYS_FUNC(fork);
extern SYS_FUNC(fremovexattr);
extern SYS_FUNC(fsetxattr);
extern SYS_FUNC(fstat);
extern SYS_FUNC(fstat64);
extern SYS_FUNC(fstatfs);
extern SYS_FUNC(fstatfs64);
extern SYS_FUNC(ftruncate);
extern SYS_FUNC(ftruncate64);
extern SYS_FUNC(futex);
extern SYS_FUNC(futimesat);
extern SYS_FUNC(fxstat);
extern SYS_FUNC(getcpu);
extern SYS_FUNC(getcwd);
extern SYS_FUNC(getdents);
extern SYS_FUNC(getdents64);
extern SYS_FUNC(getdtablesize);
extern SYS_FUNC(getgroups);
extern SYS_FUNC(gethostname);
extern SYS_FUNC(getitimer);
extern SYS_FUNC(get_mempolicy);
extern SYS_FUNC(getmsg);
extern SYS_FUNC(getpagesize);
extern SYS_FUNC(getpmsg);
extern SYS_FUNC(getpriority);
extern SYS_FUNC(getrandom);
extern SYS_FUNC(getresuid);
extern SYS_FUNC(getrlimit);
extern SYS_FUNC(get_robust_list);
extern SYS_FUNC(getrusage);
extern SYS_FUNC(getsockname);
extern SYS_FUNC(getsockopt);
extern SYS_FUNC(get_thread_area);
extern SYS_FUNC(gettimeofday);
extern SYS_FUNC(getuid);
extern SYS_FUNC(getxattr);
extern SYS_FUNC(init_module);
extern SYS_FUNC(inotify_add_watch);
extern SYS_FUNC(inotify_init1);
extern SYS_FUNC(inotify_rm_watch);
extern SYS_FUNC(io_cancel);
extern SYS_FUNC(ioctl);
extern SYS_FUNC(io_destroy);
extern SYS_FUNC(io_getevents);
extern SYS_FUNC(ioprio_get);
extern SYS_FUNC(ioprio_set);
extern SYS_FUNC(io_setup);
extern SYS_FUNC(io_submit);
extern SYS_FUNC(ipc);
extern SYS_FUNC(kexec_load);
extern SYS_FUNC(keyctl);
extern SYS_FUNC(kill);
extern SYS_FUNC(link);
extern SYS_FUNC(linkat);
extern SYS_FUNC(listen);
extern SYS_FUNC(listxattr);
extern SYS_FUNC(llseek);
extern SYS_FUNC(lseek);
extern SYS_FUNC(madvise);
extern SYS_FUNC(mbind);
extern SYS_FUNC(migrate_pages);
extern SYS_FUNC(mincore);
extern SYS_FUNC(mknod);
extern SYS_FUNC(mknodat);
extern SYS_FUNC(mlockall);
extern SYS_FUNC(mmap);
extern SYS_FUNC(mmap_4koff);
extern SYS_FUNC(mmap_pgoff);
extern SYS_FUNC(modify_ldt);
extern SYS_FUNC(mount);
extern SYS_FUNC(move_pages);
extern SYS_FUNC(mprotect);
extern SYS_FUNC(mq_getsetattr);
extern SYS_FUNC(mq_notify);
extern SYS_FUNC(mq_open);
extern SYS_FUNC(mq_timedreceive);
extern SYS_FUNC(mq_timedsend);
extern SYS_FUNC(mremap);
extern SYS_FUNC(msgctl);
extern SYS_FUNC(msgget);
extern SYS_FUNC(msgrcv);
extern SYS_FUNC(msgsnd);
extern SYS_FUNC(msync);
extern SYS_FUNC(munmap);
extern SYS_FUNC(nanosleep);
extern SYS_FUNC(newfstatat);
extern SYS_FUNC(oldfstat);
extern SYS_FUNC(old_mmap);
extern SYS_FUNC(old_mmap_pgoff);
extern SYS_FUNC(oldselect);
extern SYS_FUNC(oldstat);
extern SYS_FUNC(open);
extern SYS_FUNC(openat);
extern SYS_FUNC(or1k_atomic);
extern SYS_FUNC(osf_fstatfs);
extern SYS_FUNC(osf_getitimer);
extern SYS_FUNC(osf_getrusage);
extern SYS_FUNC(osf_gettimeofday);
extern SYS_FUNC(osf_select);
extern SYS_FUNC(osf_setitimer);
extern SYS_FUNC(osf_settimeofday);
extern SYS_FUNC(osf_statfs);
extern SYS_FUNC(osf_utimes);
extern SYS_FUNC(osf_wait4);
extern SYS_FUNC(perf_event_open);
extern SYS_FUNC(personality);
extern SYS_FUNC(pipe);
extern SYS_FUNC(pipe2);
extern SYS_FUNC(poll);
extern SYS_FUNC(ppoll);
extern SYS_FUNC(prctl);
extern SYS_FUNC(pread);
extern SYS_FUNC(preadv);
extern SYS_FUNC(prlimit64);
extern SYS_FUNC(process_vm_readv);
extern SYS_FUNC(process_vm_writev);
extern SYS_FUNC(pselect6);
extern SYS_FUNC(ptrace);
extern SYS_FUNC(putmsg);
extern SYS_FUNC(putpmsg);
extern SYS_FUNC(pwrite);
extern SYS_FUNC(pwritev);
extern SYS_FUNC(query_module);
extern SYS_FUNC(quotactl);
extern SYS_FUNC(read);
extern SYS_FUNC(readahead);
extern SYS_FUNC(readdir);
extern SYS_FUNC(readlink);
extern SYS_FUNC(readlinkat);
extern SYS_FUNC(readv);
extern SYS_FUNC(reboot);
extern SYS_FUNC(recv);
extern SYS_FUNC(recvfrom);
extern SYS_FUNC(recvmmsg);
extern SYS_FUNC(recvmsg);
extern SYS_FUNC(remap_file_pages);
extern SYS_FUNC(removexattr);
extern SYS_FUNC(renameat);
extern SYS_FUNC(renameat2);
extern SYS_FUNC(request_key);
extern SYS_FUNC(restart_syscall);
extern SYS_FUNC(rt_sigaction);
extern SYS_FUNC(rt_sigpending);
extern SYS_FUNC(rt_sigprocmask);
extern SYS_FUNC(rt_sigqueueinfo);
extern SYS_FUNC(rt_sigsuspend);
extern SYS_FUNC(rt_sigtimedwait);
extern SYS_FUNC(rt_tgsigqueueinfo);
extern SYS_FUNC(sched_getaffinity);
extern SYS_FUNC(sched_getparam);
extern SYS_FUNC(sched_get_priority_min);
extern SYS_FUNC(sched_getscheduler);
extern SYS_FUNC(sched_rr_get_interval);
extern SYS_FUNC(sched_setaffinity);
extern SYS_FUNC(sched_setparam);
extern SYS_FUNC(sched_setscheduler);
extern SYS_FUNC(seccomp);
extern SYS_FUNC(select);
extern SYS_FUNC(semctl);
extern SYS_FUNC(semget);
extern SYS_FUNC(semop);
extern SYS_FUNC(semtimedop);
extern SYS_FUNC(send);
extern SYS_FUNC(sendfile);
extern SYS_FUNC(sendfile64);
extern SYS_FUNC(sendmmsg);
extern SYS_FUNC(sendmsg);
extern SYS_FUNC(sendto);
extern SYS_FUNC(setfsuid);
extern SYS_FUNC(setgroups);
extern SYS_FUNC(sethostname);
extern SYS_FUNC(setitimer);
extern SYS_FUNC(set_mempolicy);
extern SYS_FUNC(setns);
extern SYS_FUNC(setpriority);
extern SYS_FUNC(setresuid);
extern SYS_FUNC(setreuid);
extern SYS_FUNC(setrlimit);
extern SYS_FUNC(setsockopt);
extern SYS_FUNC(set_thread_area);
extern SYS_FUNC(settimeofday);
extern SYS_FUNC(setuid);
extern SYS_FUNC(setxattr);
extern SYS_FUNC(shmat);
extern SYS_FUNC(shmctl);
extern SYS_FUNC(shmdt);
extern SYS_FUNC(shmget);
extern SYS_FUNC(shutdown);
extern SYS_FUNC(sigaction);
extern SYS_FUNC(sigaltstack);
extern SYS_FUNC(siggetmask);
extern SYS_FUNC(signal);
extern SYS_FUNC(signalfd);
extern SYS_FUNC(signalfd4);
extern SYS_FUNC(sigpending);
extern SYS_FUNC(sigprocmask);
extern SYS_FUNC(sigreturn);
extern SYS_FUNC(sigsetmask);
extern SYS_FUNC(sigsuspend);
extern SYS_FUNC(socket);
extern SYS_FUNC(socketcall);
extern SYS_FUNC(socketpair);
extern SYS_FUNC(splice);
extern SYS_FUNC(sram_alloc);
extern SYS_FUNC(stat);
extern SYS_FUNC(stat64);
extern SYS_FUNC(statfs);
extern SYS_FUNC(statfs64);
extern SYS_FUNC(subpage_prot);
extern SYS_FUNC(swapon);
extern SYS_FUNC(symlinkat);
extern SYS_FUNC(sync_file_range);
extern SYS_FUNC(sync_file_range2);
extern SYS_FUNC(sysctl);
extern SYS_FUNC(sysinfo);
extern SYS_FUNC(syslog);
extern SYS_FUNC(sysmips);
extern SYS_FUNC(tee);
extern SYS_FUNC(tgkill);
extern SYS_FUNC(time);
extern SYS_FUNC(timer_create);
extern SYS_FUNC(timerfd);
extern SYS_FUNC(timerfd_create);
extern SYS_FUNC(timerfd_gettime);
extern SYS_FUNC(timerfd_settime);
extern SYS_FUNC(timer_gettime);
extern SYS_FUNC(timer_settime);
extern SYS_FUNC(times);
extern SYS_FUNC(truncate);
extern SYS_FUNC(truncate64);
extern SYS_FUNC(umask);
extern SYS_FUNC(umount2);
extern SYS_FUNC(uname);
extern SYS_FUNC(unlinkat);
extern SYS_FUNC(unshare);
extern SYS_FUNC(utime);
extern SYS_FUNC(utimensat);
extern SYS_FUNC(utimes);
extern SYS_FUNC(vmsplice);
extern SYS_FUNC(wait4);
extern SYS_FUNC(waitid);
extern SYS_FUNC(waitpid);
extern SYS_FUNC(write);
extern SYS_FUNC(writev);
extern SYS_FUNC(xmknod);
extern SYS_FUNC(xstat);
