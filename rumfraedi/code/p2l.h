double p2l(pt p, pt l1, pt l2)
{
	double t = (real(l2 - l1)*real(p - l1) + imag(l2 - l1)*imag(p - l1))
		/norm(l2 - l1);
	if (t > 0.0 && t < 1.0) return abs(l1 + t*(l2 - l1) - p);
	return fmin(abs(l1 - p), abs(l2 - p));
}
