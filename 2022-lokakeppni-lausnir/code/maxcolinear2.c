#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPS 1e-9
typedef long long ll;

typedef struct { double x, s; } lina;
lina tolina(double x, double s) { lina r = {x, s}; return r; }
int cmp(const void *p1, const void *p2)
{
	lina a = *(lina*)p1, b = *(lina*)p2;
	if (fabs(a.s - b.s) < EPS && fabs(a.x - b.x) < EPS) return 0;
	if (fabs(a.s - b.s) < EPS) return a.x < b.x ? -1 : 1;
	return a.s < b.s ? -1 : 1;
}

int main()
{
	ll i, j, n;
	scanf("%lld", &n);
	while (n)
	{
		double x[n], y[n];
		ll k = 0, r = 0;
		lina a[n*n];
		for (i = 0; i < n; i++) scanf("%lf%lf", &x[i], &y[i]);
		if (n == 1) { printf("1\n"); scanf("%lld", &n); continue; }
		for (i = 0; i < n; i++) for (j = 0; j < i; j++)
		{
			if (fabs(x[i] - x[j]) < EPS) a[k++] = tolina(x[i], 1e18);
			else
			{
				double s = (y[i] - y[j])/(x[i] - x[j]);
				a[k++] = tolina(y[i] - s*x[i], s);
			}
		}
		qsort(a, k, sizeof *a, cmp);
		i = 0;
		while (i < k)
		{
			j = i;
			while (j < k && fabs(a[i].s - a[j].s) < EPS
					&& fabs(a[i].x - a[j].x) < EPS) j++;
			r = r < j - i ? j - i : r;
			i = j;
		}
		printf("%d\n", (int)(1.0 + 0.5*sqrt(1.0 + 8.0*r)));
		scanf("%lld", &n);
	}
	return 0;
}
