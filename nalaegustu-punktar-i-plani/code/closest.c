#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
typedef complex double pt;

int cmpx(const void* p1, const void* p2)
{
	double a = creal(*(pt*)p1), b = creal(*(pt*)p2);
	if (fabs(a - b) < 1e-9) return 0;
	if (a < b) return -1;
	return 1;
}

void merge(pt* a, pt *b, int m, int r)
{ // Úr D&D glærunum.
	int i = 0, j = m, c = 0;
	while (i < m && j < r) b[c++] = a[cimag(a[j]) < cimag(a[i]) ? j++ : i++];
	while (i < m || j < r) b[c++] = a[j < r ? j++ : i++];
	for (i = 0; i < r; i++) a[i] = b[i];
}

double closest_pair_r(pt *a, pt *b, pt *c, int n, pt *r1, pt *r2)
{ // Hjálparfall
	if (n < 2) { b[0] = a[0]; return 1e16; }
	if (n == 2)
	{
		*r1 = b[0] = a[0], *r2 = b[1] = a[1], merge(b, c, 1, 2);
		return cnorm(*r1 - *r2);
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
	while (n != 0)
	{
		pt a[n], x, y;
		for (i = 0; i < n; i++)
		{
			double x, y;
			scanf("%lf%lf\n", &x, &y);
			a[i] = x + I*y;
		}
		closest_pair(a, n, &x, &y);
		printf("%.8f %.8f %.8f %.8f\n", creal(x), cimag(x), creal(y), cimag(y));
		scanf("%d", &n);
	}
	return 0;
}

