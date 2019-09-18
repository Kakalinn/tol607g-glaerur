// p[0] == p[n - 1]
double ummal(polygon p)
{
	int i;
	double r = 0.0;
	for (i = 0; i < p.size() - 1; i++)
	{
		r = r + abs(p[i] - p[i + 1]);
	}
	return r;
}
