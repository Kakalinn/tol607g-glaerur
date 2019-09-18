point piv;
bool cmp(point a, point b)
{
	return fabs(arg(a - piv) - arg(b - piv)) < EPS ?
		abs(a - piv) < abs(b - piv) :
		arg(a - piv) < arg(b - piv);
}

int ccw(point a, point b, point c)
{
	return real(b - a)*imag(c - a) - imag(b - a)*real(c - a) > 0.0 ? 1 : 0;
}

polygon convex_hull(vector<point> p)
{
	polygon h; int j, i, mn = 0;
	for (i = 1; i < p.size(); i++)
		if (imag(p[i]) < imag(p[mn]) ||
				imag(p[i]) == imag(p[mn]) && real(p[i]) < imag(p[mn]))
			mn = i;
	swap(p[mn], p[0]); piv = p[0]; 
	sort(p.begin() + 1, p.end(), cmp);
	h.push_back(p[p.size() - 1]); h.push_back(p[0]); h.push_back(p[1]);
	i = 2;
	while (i < p.size())
	{
		j = h.size() - 1;
		if (ccw(h[j - 1], h[j], p[i])) h.push_back(p[i++]);
		else h.pop_back();
	}

	return h;
}
