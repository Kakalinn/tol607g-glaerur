#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define EPS 1e-9

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


#if 0
9
-1 1
0 1
1 1
-1 0
0 0
1 0
-1 -1
0 -1
1 -1
#endif

int main()
{
	int i, n, m, x, y;
	scanf("%d", &n);
	pt a[n], h[n];
	rep(i, n)
	{
		scanf("%d%d", &x, &y);
		a[i] = x + y*I;
	}
	m = convex_hull(a, h, n);
	printf("%d\n", m);
	rep(i, m) printf("%.2f %.2f\n", creal(h[i]), cimag(h[i]));
}
