/* Generated by ./xlat/gen.sh from ./xlat/at_flags.in; do not edit. */

const struct xlat at_flags[] = {
#if defined(AT_SYMLINK_NOFOLLOW) || (defined(HAVE_DECL_AT_SYMLINK_NOFOLLOW) && HAVE_DECL_AT_SYMLINK_NOFOLLOW)
 XLAT(AT_SYMLINK_NOFOLLOW),
#endif
#if defined(AT_REMOVEDIR) || (defined(HAVE_DECL_AT_REMOVEDIR) && HAVE_DECL_AT_REMOVEDIR)
 XLAT(AT_REMOVEDIR),
#endif
#if defined(AT_SYMLINK_FOLLOW) || (defined(HAVE_DECL_AT_SYMLINK_FOLLOW) && HAVE_DECL_AT_SYMLINK_FOLLOW)
 XLAT(AT_SYMLINK_FOLLOW),
#endif
#if defined(AT_NO_AUTOMOUNT) || (defined(HAVE_DECL_AT_NO_AUTOMOUNT) && HAVE_DECL_AT_NO_AUTOMOUNT)
 XLAT(AT_NO_AUTOMOUNT),
#endif
#if defined(AT_EMPTY_PATH) || (defined(HAVE_DECL_AT_EMPTY_PATH) && HAVE_DECL_AT_EMPTY_PATH)
 XLAT(AT_EMPTY_PATH),
#endif
 XLAT_END
};
