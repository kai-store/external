/* Generated by ./xlat/gen.sh from ./xlat/pr_mce_kill_policy.in; do not edit. */

static const struct xlat pr_mce_kill_policy[] = {
#if !(defined(PR_MCE_KILL_LATE) || (defined(HAVE_DECL_PR_MCE_KILL_LATE) && HAVE_DECL_PR_MCE_KILL_LATE))
# define PR_MCE_KILL_LATE 0
#endif
 XLAT(PR_MCE_KILL_LATE),
#if !(defined(PR_MCE_KILL_EARLY) || (defined(HAVE_DECL_PR_MCE_KILL_EARLY) && HAVE_DECL_PR_MCE_KILL_EARLY))
# define PR_MCE_KILL_EARLY 1
#endif
 XLAT(PR_MCE_KILL_EARLY),
#if !(defined(PR_MCE_KILL_DEFAULT) || (defined(HAVE_DECL_PR_MCE_KILL_DEFAULT) && HAVE_DECL_PR_MCE_KILL_DEFAULT))
# define PR_MCE_KILL_DEFAULT 2
#endif
 XLAT(PR_MCE_KILL_DEFAULT),
 XLAT_END
};
