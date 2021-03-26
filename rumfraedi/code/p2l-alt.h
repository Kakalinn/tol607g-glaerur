double p2l(pt p, pt l1, pt l2)
{ // fjarlaegd fra punkti ad linustriki
	p = (p - l1)*cexp(-I*carg(l2 - l1)); l2 -= l1;
	if (-EPS < creal(p) && creal(p) < cabs(l2) + EPS)
		return fabs(cimag(p));
	return fmin(cabs(p), cabs(p - cabs(l2)));
}

double p2l(pt p, pt l1, pt l2)
{ // fjarlaegd fra punkti ad linu
	return fabs(cimag((p - l1)*cexp(-I*carg(l2 - l1))));
}
