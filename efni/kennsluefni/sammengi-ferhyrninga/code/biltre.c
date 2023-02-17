#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define MAXN 200000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
// Ef n = 10^5 þarf SQRT að vera ca. 500, a.m.k. þarf SQRT^2 > 2*n.
typedef long long ll;
ll min(ll a, ll b) { return a < b ? a : b; }

typedef struct { ll x, y, z, w; } par;
par topar(ll x, ll y, ll z, ll w)
{
	par r = {x, y, z, w};
	return r;
}

// Gögn hvers hnúts í trénu.
typedef struct { ll v, o, mn, mc; } data;

#define CMP(E, F) (F <= E) - (E <= F)
int cmp(const void* p1, const void* p2)
{
	return CMP(*(ll*)p1, *(ll*)p2);
}

data p[5*MAXN];
void prop(ll x, ll y, ll e) //Hjálparfall
{ // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
	p[e].mn += p[e].o;
	if (x != y) p[LEFT(e)].o += p[e].o, p[RIGHT(e)].o += p[e].o;
	p[e].o = 0;
}

ll qrec(ll i, ll j, ll x, ll y, ll e) // Hjálparfall
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) return p[e].mn == 0 ? p[e].mc : 0;
	ll m = (i + j)/2;
	if (y <= m) return qrec(i, m, x, y, LEFT(e));
	else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));
	return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
}
ll query(ll x, ll y)
{ // Finnum fjölda núlla á [x, y[.
	return qrec(0, p[0].v - 1, x, y - 1, 1);
}

void urec(ll i, ll j, ll x, ll y, ll z, ll e) // Hjálparfall
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) { p[e].o = z; return; }
	ll m = (i + j)/2, v1, v2;
	if (y <= m) urec(i, m, x, y, z, LEFT(e));
	else if (x > m) urec(m + 1, j, x, y, z, RIGHT(e));
	else urec(i, m, x, m, z, LEFT(e)), urec(m + 1, j, m + 1, y, z, RIGHT(e));
	v1 = p[LEFT(e)].mn + p[LEFT(e)].o, v2 = p[RIGHT(e)].mn + p[RIGHT(e)].o;
	p[e].mn = min(v1, v2);
	p[e].mc = (v1 <= v2)*p[LEFT(e)].mc + (v1 >= v2)*p[RIGHT(e)].mc;
}
void update(ll x, ll y, ll z)
{ // Bætum z við stökin á bilinu [x, y[
	urec(0, p[0].v - 1, x, y - 1, z, 1);
}

void irec(ll *a, ll i, ll j, ll e) // Hjálparfall
{
	if (i == j) { p[e].o = p[e].v = p[e].mn = 0, p[e].mc = a[i], p[e].v = a[i]; return; }
	ll m = (i + j)/2;
	irec(a, i, m, LEFT(e)), irec(a, m + 1, j, RIGHT(e));
	p[e].o = p[e].v = p[e].mn = 0, p[e].mc = p[LEFT(e)].mc + p[RIGHT(e)].mc;
	p[e].v = p[LEFT(e)].v + p[RIGHT(e)].v;
}
void init(ll *a, ll w, ll n)
{ // Upphafstillum.
	p[0].o = w, irec(a, 0, (p[0].v = n) - 1, 1);
}

ll find(ll *a, ll t, ll n)
{
	ll r = -1, s;
	for (s = n; s >= 1; s /= 2) while (r + s < n && a[r + s] < t) r += s;
	return r + 1;
}

ll sammengi_ferhyrninga(ll *x1, ll *y1, ll *x2, ll *y2, ll n)
{
	ll i, m = 2*n, k, r = 0, a[m], b[m];
	par e[2*n];
	for (i = k = 0; i < n; i++) a[k++] = y1[i], a[k++] = y2[i];
	qsort(a, m, sizeof *a, cmp);
	for (i = 0; i < m - 1; i++) b[i] = a[i + 1] - a[i];
	b[m - 1] = 0;
	init(b, a[m - 1] - a[0], m);
	for (i = k = 0; i < n; i++) 
		e[k++] = topar(x1[i], find(a, y1[i], m), find(a, y2[i], m), 1),
		e[k++] = topar(x2[i], find(a, y1[i], m), find(a, y2[i], m), -1);
	qsort(e, m, sizeof *e, cmp);
	//for (i = 0; i < m; i++) printf(">> >> >> >> %lld %lld %lld\n", e[i].x, e[i].y, e[i].z); printf("\n");
	//printf("%4lld %4lld %4lld %4lld %4lld %4lld\n", b[0], b[1], b[2], b[3], b[4], b[5]);
	for (i = 0; i < m; i++)
	{
		//printf(">>>>>> %lld %lld %lld %lld : %lld\n", query(0, 1), query(1, 2), query(2, 3), query(3, 4), p[1].mc);
		//if (i != 0) printf(">>>>>> %lld %lld\n", query(0, m), e[i].x - e[i - 1].x);
		if (i != 0) r += query(0, m)*(e[i].x - e[i - 1].x)
							//,printf("number: %lld\n", query(0, m))
							;
		//printf(">> updating %lld %lld %lld\n", e[i].y, e[i].z, e[i].w);
		update(e[i].y, e[i].z, e[i].w);
	}
	return (a[m - 1] - a[0])*(e[m - 1].x - e[0].x) - r;
}

#define PROBLEM 1
#if PROBLEM == 1
// iceland.veggspjold
int main()
{
	ll w, h, n, i;
	scanf("%lld%lld%lld", &w, &h, &n);
	ll x1[n], y1[n], x2[n], y2[n];
	for (i = 0; i < n; i++) scanf("%lld%lld%lld%lld", &x1[i], &x2[i], &y1[i], &y2[i]);
	printf("%lld\n", w*h - sammengi_ferhyrninga(x1, y1, x2, y2, n));
	return 0;
}
#elif PROBLEM == 2
// gameworld
int main()
{
	ll n, i;
	scanf("%lld", &n);
	ll x1[n], y1[n], x2[n], y2[n];
	for (i = 0; i < n; i++) scanf("%lld%lld%lld%lld", &x1[i], &y1[i], &x2[i], &y2[i]);
	printf("%lld\n", sammengi_ferhyrninga(x1, y1, x2, y2, n));
	return 0;
}
#elif PROBLEM == 3
// unrealestate
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
#else
#error "Óþekkt dæmi valið!"
#endif
