// alpha í glaerunum
double angle(pt a, pt o, pt b)
{
	double r = fabs(arg(a - o) - arg(b - o));
	return r < M_PI ? r : 2*M_PI - r;
}

int beta(pt a, pt b, pt c)
{
	return imag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

int is_in(polygon& p, pt q)
{
	int i;
	double s = 0.0;
	for (i = 0; i < p.size() - 1; i++)
		s = s + beta(q, p[i], p[i + 1])*angle(p[i], q, p[i + 1]);
	return (fabs(s) > M_PI ? 1 : 0);
}
