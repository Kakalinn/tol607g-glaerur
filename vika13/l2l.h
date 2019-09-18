double l2l(point a1, point a2, point b1, point b2)
{
	if (fabs(abs(a1 - a2)) < EPS && fabs(abs(b1 - b2)) < EPS)
		return abs(a1 - b1);
	if (fabs(abs(a1 - a2)) < EPS) return p2l(a1, b1, b2);
	if (fabs(abs(b1 - b2)) < EPS) return p2l(b1, a1, a2);
	if (lxl(a1, a2, b1, b2)) return 0.0;
	return fmin(fmin(p2l(a1, b1, b2), p2l(a2, b1, b2)),
			    fmin(p2l(b1, a1, a2), p2l(b2, a1, a2)));
}
