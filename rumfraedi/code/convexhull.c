#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define EPS 1e-9
int get_int();

typedef double complex pt;

int ccw(pt a, pt b, pt c)
{
	if (cabs(a - b) < EPS || fabs(cimag((c - a)/(b - a))) < EPS) return 0;
	return cimag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
int cmp(const void* p1, const void* p2)
{
	pt a = *(pt*)p1, b = *(pt*)p2;
	if (fabs(carg(a - piv) - carg(b - piv)) > EPS)
		return carg(a - piv) < carg(b - piv) ? -1 : 1;
	if (fabs(cabs(a - piv) - cabs(b - piv)) < EPS) return 0;
		return cabs(a - piv) < cabs(b - piv) ? -1 : 1;
}

int convex_hull(pt* p, pt* h, int n)
{
	int j = 0, i, mn = 0;
	for (i = 1; i < n; i++)
		if (cimag(p[i]) < cimag(p[mn]) || cimag(p[i]) == cimag(p[mn])
				&& creal(p[i]) < creal(p[mn])) mn = i;
	pt t = p[mn]; p[mn] = p[0]; p[0] = t;
	piv = p[0]; 
	qsort(p + 1, n - 1, sizeof(p[1]), cmp);
	for (i = 1; i < n && cabs(p[0] - p[i]) < EPS; i++);
	if (i == n) h[j++] = p[0];
	else if (i == n - 1) h[j++] = p[0], h[j++] = p[n - 1];
	if (i >= n - 1) return j;
	h[j++] = p[n - 1], h[j++] = p[0], h[j++] = p[i];
	if (ccw(h[0], h[1], h[2]) == 0)
		return j - (cabs(h[0] - h[1]) < EPS ? 2 : 1);
	for (i++; i < n;)
		(cabs(h[j - 1] - p[i]) > EPS && ccw(h[j - 2], h[j - 1], p[i]) == 1)
			? (h[j++] = p[i++]) : j--;
	return --j;
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
		pt a[n], h[n];
		rep(i, n)
		{
			int x = get_int(), y = get_int();
			a[i] = x + y*I;
		}
		int m = convex_hull(a, h, n);
		printf("%d\n", m);
		rep(i, m) printf("%d %d\n", rnd(creal(h[i])), rnd(cimag(h[i])));
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
