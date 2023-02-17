#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define SQRT 448
// Ef n = 10^5 þarf SQRT að vera ca. 500, a.m.k. þarf SQRT^2 > 2*n.
typedef long long ll;
ll min(ll a, ll b) { return a < b ? a : b; }

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

ll s[SQRT][SQRT], a[SQRT*SQRT + 1], o[SQRT], mn[SQRT], mnx[SQRT];
void prop(ll x)
{
	ll i;
	for (i = 0; i < SQRT; i++) s[x][i] += o[x];
	o[x] = 0;
}

void fix(ll x)
{ // fix bucket x.
	ll i;
	prop(x);
	mn[x] = (1LL << 60);
	for (i = 0; i < SQRT; i++) mn[x] = min(mn[x], s[x][i]);
	mnx[x] = 0;
	for (i = 0; i < SQRT; i++) mnx[x] += (mn[x] == s[x][i])*(a[x*SQRT + i + 1] - a[x*SQRT + i]);
}

void init()
{
	ll i, j;
	for (i = 0; i < SQRT; i++) for (j = 0; j < SQRT; j++) s[i][j] = 0;
	for (i = 0; i < SQRT; i++) o[i] = 0;
	for (i = 0; i < SQRT; i++) fix(i);
}

void update_internal(ll bx, ll x, ll by, ll y, ll z)
{
	ll i;
	prop(bx), prop(by);
	if (bx == by) for (i = x; i < y; i++) s[bx][i] += z;
	else update_internal(bx, x, bx, SQRT, z), update_internal(by, 0, by, y, z);
	for (i = bx + 1; i < by; i++) o[i] += z;
	fix(bx), fix(by);
}
void update(ll x, ll y, ll z)
{
	update_internal(x/SQRT, x%SQRT, y/SQRT, y%SQRT, z);
}

ll query_internal(ll bx, ll x, ll by, ll y)
{ // telja núllur
	ll i, r = 0;
	prop(bx), prop(by), fix(bx), fix(by);
	if (bx == by) for (i = x; i < y; i++) r += (s[bx][i] == 0)*(a[bx*SQRT + i + 1] - a[bx*SQRT + i]);
	else r += query_internal(bx, x, bx, SQRT), r += query_internal(by, 0, by, y);
	for (i = bx + 1; i < by; i++) if (mn[i] + o[i] == 0) r += mnx[i];
	return r;
}
ll query(ll x, ll y)
{
	ll q = query_internal(x/SQRT, x%SQRT, y/SQRT, y%SQRT);
	return a[y] - a[x] - q;
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
	par e[2*n];
	for (i = k = 0; i < n; i++) a[k++] = y1[i], a[k++] = y2[i];
	qsort(a, m, sizeof *a, cmp);
	for (i = m; i < SQRT*SQRT + 1; i++) a[i] = a[m - 1];
	init();
	for (i = k = 0; i < n; i++) 
		e[k++] = topar(x1[i], find(a, y1[i], 2*n), find(a, y2[i], 2*n), 1),
		e[k++] = topar(x2[i], find(a, y1[i], 2*n), find(a, y2[i], 2*n), -1);
	qsort(e, m, sizeof *e, cmp);
	for (i = 0; i < m; i++)
	{
		if (i != 0) r += query(0, m)*(e[i].x - e[i - 1].x);
		update(e[i].y, e[i].z, e[i].w);
	}
	return r;
}

#if 1
// Þetta leysir gameworld naumlega.
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
