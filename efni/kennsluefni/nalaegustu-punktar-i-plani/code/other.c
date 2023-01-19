#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
typedef complex double pt;

int cmpx(const void* p1, const void* p2)
{
	double a = creal(*(pt*)p1), b = creal(*(pt*)p2);
	if (fabs(a - b) < 1e-9) return 0;
	if (a < b) return -1;
	return 1;
}

void merge(pt* a, pt *b, int m, int r)
{
	int i = 0, j = m, c = 0;
	while (i < m && j < r)
		cimag(a[j]) < cimag(a[i]) ? (b[c++] = a[j++]) : (b[c++] = a[i++]);
	while (i < m) b[c++] = a[i++];
	while (j < r) b[c++] = a[j++];
	for (i = 0; i < r; i++) a[i] = b[i];
}
double closest_pair_r(pt *a, pt *b, pt *c, int n, pt *r1, pt *r2)
{ // Hjálparfall
	if (n < 2) { b[0] = a[0]; return 1e16; }
	if (n == 2)
	{
		*r1 = b[0] = a[0], *r2 = b[1] = a[1], merge(b, c, 1, 2);
		return cabs(*r1 - *r2);
	}
	int m = n/2, i, j, k = 0;
	pt r3, r4;
	double p = closest_pair_r(a, b, c, m, r1, r2), d;
	b[m] = a[m];
	d = closest_pair_r(a + m + 1, b + m + 1, c + m + 1, n - m - 1, &r3, &r4);
	if (d < p) p = d, *r1 = r3, *r2 = r4;
	merge(b, c, m, m + 1), merge(b, c, m + 1, n);
	for (i = 0; i < n; i++) if (fabs(creal(b[i] - a[m])) < p) c[k++] = b[i];
	for (i = 0; i < k; i++)
		for (j = i + 1; cimag(c[j] - c[i]) < p && j < k; j++)
			if (cabs(c[i] - c[j]) < p)
				p = cabs(c[i] - c[j]), *r1 = c[i], *r2 = c[j];
	return p;
}
double closest_pair(pt *a, int n, pt *r1, pt *r2)
{ // Skilar lengd milli nálægustu punkta í a: r1 og r2.
	pt b[n], c[n];
	qsort(a, n, sizeof(a[0]), cmpx);
	return closest_pair_r(a, b, c, n, r1, r2);
}

int main()
{
	int i, n;
	scanf("%d", &n);
	pt a[n], x, y, z;
	rep(i, n)
	{
		double x, y;
		scanf("%lf%lf", &x, &y);
		a[i] = x + I*y;
	}
	double r1 = closest_pair(a, n, &x, &z);
	rep(i, n) if (cabs(x - a[i]) < 1e-9) break;
	pt s = a[i];
	a[i] = a[n - 1];
	a[n - 1] = s;
	double r2 = closest_pair(a, n - 1, &x, &y);
	rep(i, n - 1) if (cabs(a[i] - z) > 1e-9) r2 = fmin(r2, cabs(a[n - 1] - a[i]));
	printf("%.8f\n%.8f\n", r1, r2);
	return 0;
}

