/* Generated by ./xlat/gen.sh from ./xlat/policies.in; do not edit. */

static const struct xlat policies[] = {
#if defined(MPOL_DEFAULT) || (defined(HAVE_DECL_MPOL_DEFAULT) && HAVE_DECL_MPOL_DEFAULT)
 XLAT(MPOL_DEFAULT),
#endif
#if defined(MPOL_PREFERRED) || (defined(HAVE_DECL_MPOL_PREFERRED) && HAVE_DECL_MPOL_PREFERRED)
 XLAT(MPOL_PREFERRED),
#endif
#if defined(MPOL_BIND) || (defined(HAVE_DECL_MPOL_BIND) && HAVE_DECL_MPOL_BIND)
 XLAT(MPOL_BIND),
#endif
#if defined(MPOL_INTERLEAVE) || (defined(HAVE_DECL_MPOL_INTERLEAVE) && HAVE_DECL_MPOL_INTERLEAVE)
 XLAT(MPOL_INTERLEAVE),
#endif
 XLAT_END
};
