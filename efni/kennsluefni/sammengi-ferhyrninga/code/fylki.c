#include <stdio.h>
#include <stdlib.h>
#define MAXN 1000000
typedef long long ll;

typedef struct { ll x, y, z, w; } par;
par topar(ll x, ll y, ll z, ll w)
{
	par r = {x, y, z, w};
	return r;
}

#define CMP(E, F) (F <= E) - (E <= F)
int cmp(const void* p1, const void* p2)
{
	return CMP(*(ll*)p1, *(ll*)p2);
}

ll a[2*MAXN], b[2*MAXN];
void init(ll k)
{
	ll i;
	for (i = 0; i < k; i++) b[i] = 0;
}

void update(ll x, ll y, ll z)
{
	printf(">> update >>>> %lld %lld | %lld\n", x, y, z);
	while (x < y) b[x++] += z;
}

ll query(ll x, ll y)
{
	ll i, r = 0;
	for (i = x; i < y; i++) if (b[i] != 0) r += a[i + 1] - a[i];
	printf(">> query  >>>> %lld %lld | %lld\n", x, y, r);
	return r;
}

ll find(ll *a, ll t, ll n)
{
	ll r = -1, s;
	for (s = n; s >= 1; s /= 2) while (r + s < n && a[r + s] < t) r += s;
	return r + 1;
}

ll sammengi_ferhyrninga(ll *x1, ll *y1, ll *x2, ll *y2, ll n)
{
	ll i, m = 2*n, k, r = 0;
	init(m);
	par e[2*n];
	for (i = k = 0; i < n; i++) a[k++] = y1[i], a[k++] = y2[i];
	qsort(a, m, sizeof *a, cmp);
	for (i = k = 0; i < n; i++) 
		e[k++] = topar(x1[i], find(a, y1[i], 2*n), find(a, y2[i], 2*n), 1),
		e[k++] = topar(x2[i], find(a, y1[i], 2*n), find(a, y2[i], 2*n), -1);
	qsort(e, m, sizeof *e, cmp);
	for (i = 0; i < m; i++)
	{
		printf(">> >> >> >> >> %lld %lld\n", a[e[i].y], a[e[i].z]);
		if (i != 0) r += query(0, m - 1)*(e[i].x - e[i - 1].x);
		update(e[i].y, e[i].z, e[i].w);
	}
	return r;
}

#if 0
int main()
{
	ll n, i;
	scanf("%lld", &n);
	ll x1[n], y1[n], x2[n], y2[n];
	for (i = 0; i < n; i++) scanf("%lld%lld%lld%lld", &x1[i], &y1[i], &x2[i], &y2[i]);
	printf("%lld\n", sammengi_ferhyrninga(x1, y1, x2, y2, n));
	return 0;
}
#else
// Ætti að leysa unrealestate.
ll read()
{
	double r;
	scanf("%lf", &r);
	return (ll)((r + 1000.0)*100.0 + 0.5);
}

int main()
{
	ll i, j, k = 0, n, r = 0;
	scanf("%lld", &n);
	ll x1[n], y1[n], x2[n], y2[n];
	for (i = 0; i < n; i++) x1[i] = read(), y1[i] = read(), x2[i] = read(), y2[i] = read();
	printf("%.2f\n", 1e-4*sammengi_ferhyrninga(x1, y1, x2, y2, n));
	return 0;
}
#endif
