/* Generated by ./xlat/gen.sh from ./xlat/delete_module_flags.in; do not edit. */

static const struct xlat delete_module_flags[] = {
#if defined(O_NONBLOCK) || (defined(HAVE_DECL_O_NONBLOCK) && HAVE_DECL_O_NONBLOCK)
 XLAT(O_NONBLOCK),
#endif
#if defined(O_TRUNC) || (defined(HAVE_DECL_O_TRUNC) && HAVE_DECL_O_TRUNC)
 XLAT(O_TRUNC),
#endif
 XLAT_END
};
