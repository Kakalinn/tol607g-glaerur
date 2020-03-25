double flatarmal(polygon &p)
{
	int i;
	double r = 0.0;
	for (i = 0; i < p.size() - 1; i++)
		r = r + real(p[i])*imag(p[i + 1]) - real(p[i + 1])*imag(p[i]);
	return fabs(0.5*r);
}
