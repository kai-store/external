if (check_errno && sparc_regs.psr & PSR_C) {
	tcp->u_rval = -1;
	tcp->u_error = sparc_regs.u_regs[U_REG_O0];
} else {
	tcp->u_rval = sparc_regs.u_regs[U_REG_O0];
}
