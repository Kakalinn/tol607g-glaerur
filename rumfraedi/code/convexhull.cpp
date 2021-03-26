#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
#define EPS 1e-9
int get_int();

typedef complex<double> pt;
typedef vector<pt> polygon;

int ccw(pt a, pt b, pt c)
{
	if (fabs(a - b) < EPS || fabs(imag((c - a)/(b - a))) < EPS) return 0;
	return imag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
bool cmp(pt a, pt b)
{
	return fabs(arg(a - piv) - arg(b - piv)) < EPS ?
		abs(a - piv) < abs(b - piv) : arg(a - piv) < arg(b - piv);
}

polygon convex_hull(vector<pt> p)
{
	int j, i, mn = 0;
	polygon h;
	for (i = 1; i < p.size(); i++)
		if (imag(p[i]) < imag(p[mn]) ||
				imag(p[i]) == imag(p[mn]) && real(p[i]) < real(p[mn]))
			mn = i;
	swap(p[mn], p[0]);
	piv = p[0]; 
	sort(p.begin() + 1, p.end(), cmp);
	for (i = 1; i < p.size() && fabs(p[0] - p[i]) < EPS; i++);
	if (i == p.size())
	{
		h.push_back(p[0]);
		return h;
	}
	else if (i == p.size() - 1)
	{
		h.push_back(p[0]);
		h.push_back(p[p.size() - 1]);
		return h;
	}
	h.push_back(p[p.size() - 1]); h.push_back(p[0]); h.push_back(p[i]);
	if (ccw(h[0], h[1], h[2]) == 0)
	{
		h.pop_back();
		if (fabs(h[0] - h[1]) < EPS) h.pop_back();
		return h;
	}
	for (i++; i < p.size();)
	{
		j = h.size() - 1;
		if (fabs(h[j] - p[i]) > EPS && ccw(h[j - 1], h[j], p[i]) == 1) h.push_back(p[i++]);
		else h.pop_back();
	}
	h.pop_back();
	return h;
}

int rnd(double a)
{
	if (a < 0.0) return -rnd(-a);
	return (int)(a + 0.5);
}

int main()
{
	int i, n = get_int();
	while (n != 0)
	{
		vector<pt> a;
		rep(i, n)
		{
			int x = get_int(), y = get_int();
			a.emplace_back(x, y);
		}
		polygon h = convex_hull(a);
		printf("%d\n", h.size());
		rep(i, h.size())
		{
			printf("%d %d\n", rnd(real(h[i])), rnd(imag(h[i])));
		}
		n = get_int();
	}
}

int get_int()
{
	int ret = 0;
	char c = getchar();
	int sgn;

	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') { sgn = 1; break; }
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}
