// fjarlaegd fra punkti ad linustriki
double p2l(pt p, pt l1, pt l2)
{
	p = (p - l1)*exp(pt(0, -1)*arg(l2 - l1)); l2 -= l1;
	if (-EPS < real(p) && real(p) < abs(l2) + EPS) return fabs(imag(p));
	return fmin(abs(p), abs(p - abs(l2)));
}
// fjarlaegd fra punkti ad linu
double p2l(pt p, pt l1, pt l2)
{
	return fabs(imag((p - l1)*exp(pt(0, -1)*arg(l2 - l1))));
}
