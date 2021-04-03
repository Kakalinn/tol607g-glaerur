#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define EPS 1e-9
int get_int();

typedef double complex pt;

double angle(pt a, pt o, pt b)
{ // Fallid alpha(a, b, c) i glaerunum.
	double r = fabs(carg(a - o) - carg(b - o));
	return r < M_PI ? r : 2*M_PI - r;
}

int ccw(pt a, pt b, pt c)
{ // Fallid beta(a, b, c) i glaerunum.
	if (cabs(a - b) < EPS || fabs(cimag((c - a)/(b - a))) < EPS)
		return 0;
	return cimag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

int is_in(pt* p, pt q, int n)
{
	int i;
	double s = 0.0;
	rep(i, n - 1) s += ccw(q, p[i], p[i + 1])*angle(p[i], q, p[i + 1]);
	return (fabs(s) > M_PI ? 1 : 0);
}

int is_on(pt* p, pt q, int n)
{
	int i;
	rep(i, n - 1)
	{
		double a = creal(p[i]), b = creal(p[i + 1]);
		if (fmin(a, b) - EPS > creal(q) || creal(q) > fmax(a, b) + EPS) continue;
		a = cimag(p[i]), b = cimag(p[i + 1]);
		if (fmin(a, b) - EPS > cimag(q) || cimag(q) > fmax(a, b) + EPS) continue;
		if (ccw(p[i], q, p[i + 1]) == 0) return 1;
	}
	return 0;
}

int main()
{
	int i, q, n = get_int() + 1;
	while (n != 1)
	{
		pt a[n];
		rep(i, n - 1)
		{
			int x = get_int(), y = get_int();
			a[i] = x + y*I;
		}
		a[n - 1] = a[0];
		q = get_int();
		while (q--)
		{
			int x = get_int(), y = get_int();
			if (is_on(a, x + I*y, n)) printf("on\n");
			else if (is_in(a, x + I*y, n)) printf("in\n");
			else printf("out\n");
		}
		n = get_int() + 1;
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
