#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 100000
typedef long long ll;
typedef __int128 lll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

ll bigprod(ll x, ll y, ll m)
{
	return ((lll)x*y)%m;
}

ll modpow(ll x, ll n, ll m)
{ 
	ll r = 1;
	while (n > 0) 
	{ 
		if (n%2 == 1) r = bigprod(r, x, m);
		n = n/2;
		x = bigprod(x, x, m);
	} 
	return r; 
}

int miller_rabin(ll n)
{
	if (n%2 == 0) return n == 2;
	if (n <= 3) return n == 3;
	ll i, k, s = 0, d = n - 1, t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	while (d%2 == 0) d /= 2, s++;
	rep(k, 12) if (t[k] <= n - 2)
	{
		ll a = t[k];
		ll x = modpow(a, d, n);
		if (x == 1 || x == n - 1) continue;
		rep(i, s - 1) if ((x = bigprod(x, x, n)) == n - 1) break;
		if (i == s - 1) return 0;
	}
	return 1;
}

ll rho(ll n)
{ // skilar vonandi thaetti i |n|
	ll s[8] = {2, 3, 4, 5, 7, 11, 13, 1031}, i, j, a, x, y, d;
	for (a = 1;; a++) rep(j, 8)
	{
		x = y = s[j], d = 1;
		while (d == 1)
		{
			x = (bigprod(x, x, n) + a)%n;
			y = (bigprod(y, y, n) + a)%n;
			y = (bigprod(y, y, n) + a)%n;
			d = gcd(llabs(x - y), n);
		}
		if (d != n) return d;
	}
}

ll e[MAXN], p[MAXN], pp = 0;
void eratos()
{
	ll i, j;
	rep(i, MAXN) e[i] = 0;
	e[0] = e[1] = -1;
	rep(i, MAXN) if (e[i] == 0)
		for (j = i; j < MAXN; j += i) if (e[j] == 0) e[j] = i;
	rep(i, MAXN) if (e[i] == i) p[pp++] = i;
}

ll a[100], c;
void pollard_rho(ll n)
{ // notar rho(...) ad ofan til ad thatta |n| og setur thaettina i |a|
	c = 0;
	ll i, s[200], ss = 0, p[6] = {2, 3, 5, 7, 11, 13};
	rep(i, 6) while (n%p[i] == 0) n /= p[i], a[c++] = p[i];
	s[ss++] = n;
	if (n == 1) return;
	while (ss > 0)
	{
		ll k = s[--ss];
		if (miller_rabin(k)) a[c++] = k;
		else
		{
			ll r = rho(k);
			s[ss++] = r;
			s[ss++] = k/r;
		}
	}
}

void test(ll x)
{
	ll i, r;
	printf("Factoring %lld...\n", x);
	pollard_rho(x);
	printf("The factors of %lld are: ", x); rep(i, c) printf("%lld ", a[i]); printf("\n");
	rep(i, c) if (!miller_rabin(a[i]))
	{
		printf("Miller-Rabin states that %lld is not a prime\n", a[i]);
		assert(0);
	}
	r = 1;
	rep(i, c) r *= a[i];
	assert(r == x);
}

ll bigrand()
{
	ll r = rand(), s = rand();
	return r*(RAND_MAX) + s;
}

int main()
{
	srand(time(NULL));
	ll e = 10, x, i, j;
	eratos();
	while (1)
	{
		//scanf("%lld", &x);
		x = bigrand()%e + 1;
		if (e*10 < e) e = 10;
		else e *= 10;
		test(x);
		test(bigrand());
		x = p[rand()%pp];
		j = x;
		while (j*x > x)
		{
			test(j);
			j *= x;
		}
	}
}

