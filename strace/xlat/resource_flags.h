/* Generated by ./xlat/gen.sh from ./xlat/resource_flags.in; do not edit. */

static const struct xlat resource_flags[] = {
#if defined(IPC_CREAT) || (defined(HAVE_DECL_IPC_CREAT) && HAVE_DECL_IPC_CREAT)
 XLAT(IPC_CREAT),
#endif
#if defined(IPC_EXCL) || (defined(HAVE_DECL_IPC_EXCL) && HAVE_DECL_IPC_EXCL)
 XLAT(IPC_EXCL),
#endif
#if defined(IPC_NOWAIT) || (defined(HAVE_DECL_IPC_NOWAIT) && HAVE_DECL_IPC_NOWAIT)
 XLAT(IPC_NOWAIT),
#endif
 XLAT_END
};
