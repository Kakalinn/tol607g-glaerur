#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef long long ll;
ll max(ll a, ll b) { return a < b ? b : a; }
typedef struct { ll x, y; } pt;
pt topt(ll x, ll y) { pt r = {x, y}; return r; }
ll ccw(pt a, pt b, pt c)
{
    ll r = a.x*(b.y - c.y) + b.x*(c.y - a.y) + c.x*(a.y - b.y);
    if (r == 0) return r;
    return r < 0 ? 1 : -1;
}

ll above(pt a)
{
	if (a.x == 0 && a.y == 0) return 2;
	return a.y < 0 ? 0 : 1;
}

int cmp(const void *p1, const void *p2)
{
	pt a = *(pt*)p1, b = *(pt*)p2;
	ll c = above(a), d = above(b);
	return c != d ? c - d : ccw(a, topt(0, 0), b);
}

int main()
{
	ll i, j, k, n, r;
	scanf("%lld", &n);
	while (n)
	{
		pt a[n], b[n];
		for (i = 0; i < n; i++) scanf("%lld%lld", &a[i].x, &a[i].y);
		if (n == 1) { printf("1\n"); scanf("%lld", &n); continue; }
		for (r = 2, i = 0; i < n; i++) 
		{
			for (j = 0; j < n; j++)
				b[j].x = a[j].x - a[i].x, b[j].y = a[j].y - a[i].y;
			qsort(b, n, sizeof *b, cmp);
			for (k = 2, j = 1; j < n - 1; j++)
				(ccw(b[j], b[j - 1], b[n - 1]) != 0)
					? (k = 2) : (r = max(r, ++k));
		}
		printf("%d\n", r);
		scanf("%lld", &n);
	}
	return 0;
}
