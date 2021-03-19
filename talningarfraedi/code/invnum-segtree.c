#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
#define MAXN 1000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
ll p[MAXN*5], pn;

ll qrec(ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	if (x == i && y == j) return p[e];
	ll m = (i + j)/2;
	if (y <= m) return qrec(i, m, x, y, LEFT(e));
	if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));
	return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
}
ll query(ll x, ll y)
{ // Finnum summuna yfir [x, y].
	return qrec(0, pn - 1, x, y, 1);
}

void urec(ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að laufinu [x, x] og erum í [i, j].
	if (i == j) p[e] += y;
	else
	{
		ll m = (i + j)/2;
		if (x <= m) urec(i, m, x, y, LEFT(e));
		else urec(m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}
void update(ll x, ll y)
{ // Bætum y við x-ta stakið.
	return urec(0, pn - 1, x, y, 1);
}

ll invnum(ll* a, ll n)
{ // Finnur fjolda umhverfinga i umroduninni sem svarar til listans |a|.
  // G.r.f. ad |a| inni haldi 0, 1, ..., n - 1.
	ll b[n], i, r = 0;
	pn = n;
	rep(i, MAXN*5) p[i] = 0;
	rep(i, n) update(i, 1);
	rep(i, n) b[a[i]] = i;
	rep(i, n) r += b[i] != 0 ? query(0, b[i] - 1) : 0, update(b[i], -1);
	return r;
}

#if 0
7
4 1 6 5 7 3 2
#endif
int main()
{
	ll n, i;
	scanf("%lld", &n);
	ll a[n];
	rep(i, n) scanf("%lld", &a[i]);
	rep(i, n) a[i]--;
	printf("%lld\n", invnum(a, n));
}
