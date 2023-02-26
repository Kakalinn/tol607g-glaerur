#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
typedef long long ll;
#define MAXN 5000100
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

#define CASE 4
#if CASE == 1
ll query(ll *p, ll x, ll y)
{ // Finnum summuna yfir [x, y].
	if (y < x) return 0;
	ll i1 = 0, i2 = 0, j1 = p[0] - 1, j2 = p[0] - 1, e1 = 1, e2 = 1, r = 0;
	while (i1 != j1 && i2 != j2)
	{
		ll m1 = (i1 + j1)/2, m2 = (i2 + j2)/2;
		(x <= m1) ? (j1 = m1, e1 = LEFT(e1)) : (i1 = m1 + 1, e1 = RIGHT(e1));
		(y <= m2) ? (j2 = m2, e2 = LEFT(e2)) : (i2 = m2 + 1, e2 = RIGHT(e2));
	}
	if (e1 == e2) return p[e1];
	r += i1 == j1 || x == i1 ? p[e1] : p[RIGHT(e1)];
	r += i2 == j2 || y == j2 ? p[e2] : p[LEFT(e2)];
	for (; e1/2 != e2/2; e1 /= 2, e2 /= 2)
		r += e1%2 ? 0 : p[e1 + 1], r += e2%2 ? p[e2 - 1] : 0;
	return r;
}

void update(ll *p, ll x, ll y)
{ // Setjum x-ta stakið sem y.
	ll i = 0, j = p[0] - 1, e = 1, m;
	for (m = (i + j)/2; i != j; m = (i + j)/2)
		(x <= m) ? (j = m, e = LEFT(e)) : (i = m + 1, e = RIGHT(e));
	p[e] += y, e /= 2;
	while (e > 0) p[e] = p[LEFT(e)] + p[RIGHT(e)], e /= 2;
}

void init(ll *p, ll n)
{
	ll i;
	for (i = 0; i < 5*n; i++) p[i] = 0;
	p[0] = n;
}
#elif CASE == 2
ll qrec(ll *p, ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	if (x == i && y == j) return p[e];
	ll m = (i + j)/2;
	if (y <= m) return qrec(p, i, m, x, y, LEFT(e));
	if (x > m) return qrec(p, m + 1, j, x, y, RIGHT(e));
	return qrec(p, i, m, x, m, LEFT(e)) + qrec(p, m + 1, j, m + 1, y, RIGHT(e));
}
ll query(ll *p, ll x, ll y)
{ // Finnum summuna yfir [x, y].
	if (y < x) return 0;
	return qrec(p, 0, p[0] - 1, x, y, 1);
}

void urec(ll *p, ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að laufinu [x, x] og erum í [i, j].
	if (i == j) p[e] += y;
	else
	{
		ll m = (i + j)/2;
		if (x <= m) urec(p, i, m, x, y, LEFT(e));
		else urec(p, m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}
void update(ll *p, ll x, ll y)
{ // Bætum y við x-ta stakið.
	return urec(p, 0, p[0] - 1, x, y, 1);
}

void init(ll *p, ll n)
{
	ll i;
	for (i = 0; i < 5*n; i++) p[i] = 0;
	p[0] = n;
}
#elif CASE == 3
ll qrec(ll *p, ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	if (x == i && y == j) return p[e];
	ll m = (i + j)/2;
	if (y <= m) return qrec(p, i, m, x, y, e + 1);
	if (x > m) return qrec(p, m + 1, j, x, y, e + 2*(m - i + 1));
	return qrec(p, i, m, x, m, e + 1) + qrec(p, m + 1, j, m + 1, y, e + 2*(m - i + 1));
}
ll query(ll *p, ll x, ll y)
{ // Finnum summuna yfir [x, y].
	if (y < x) return 0;
	return qrec(p, 0, p[0] - 1, x, y, 1);
}

void urec(ll *p, ll i, ll j, ll x, ll y, ll e) // Hjálparfall.
{ // Við erum að leita að laufinu [x, x] og erum í [i, j].
	if (i == j) p[e] += y;
	else
	{
		ll m = (i + j)/2;
		if (x <= m) urec(p, i, m, x, y, e + 1);
		else urec(p, m + 1, j, x, y, e + 2*(m - i + 1));
		p[e] = p[e + 1] + p[e + 2*(m - i + 1)];
	}
}
void update(ll *p, ll x, ll y)
{ // Bætum y við x-ta stakið.
	return urec(p, 0, p[0] - 1, x, y, 1);
}

void init(ll *p, ll n)
{
	ll i;
	for (i = 0; i < 2*n; i++) p[i] = 0;
	p[0] = n;
}
#elif CASE == 4
void init(ll *p, ll n)
{
	ll i;
	for (i = 0; i < 2*n; i++) p[i] = 0;
	p[0] = n;
}

void update(ll *p, ll w, ll value) {  // set value at position p
  for (p[w += p[0] + 1] += value; w > 1; w >>= 1) p[w>>1] = p[w] + p[w^1];
}

ll query(ll *p, ll l, ll r) {  // sum on interval [l, r)
	r++;
  ll res = 0;
  for (l += p[0] + 1, r += p[0] + 1; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += p[l++];
    if (r&1) res += p[--r];
  }
  return res;
}
#else
#error("wrong case number")
#endif

ll get_int()
{
	ll r = 0, c = getchar(), s = 1;
	while (c != '-' && (c < '0' || c > '9')) c = getchar();
	while (c == '-') s *= -1, c = getchar();
	while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
	return s*r;
}

int main()
{
	ll n = get_int(), q = get_int(),
#if CASE == 3 
	   p[2*(n + 1)];
#elif CASE == 4
	   p[2*(n + 1)];
#else
	   p[5*(n + 1)];
#endif
	init(p, n + 1);
	while (q--)
	{
		char c = getchar();
		if (c == '+')
		{
			ll x = get_int(), y = get_int();
			update(p, x, y);
		}
		else
		{
			ll x = get_int();
			printf("%lld\n", query(p, 0, x - 1));
		}
	}
	return 0;
}
