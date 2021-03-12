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
	lll a = x;
	a = a*y;
	return (ll)(a%m);
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

int miller_rabin(ll n, ll k)
{
	if (n%2 == 0) return n == 2;
	if (n <= 3) return n == 3;
	ll i, s = 0, d = n - 1, t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	while (d%2 == 0) d /= 2, s++;
	rep(k, 12) if (t[k] <= n - 2)
	{
		ll a = t[k];
		lll x = modpow(a, d, n);
		if (x == 1 || x == n - 1) continue;
		rep(i, s - 1) if ((x = bigprod(x, x, n)) == n - 1) break;
		if (i == s - 1) return 0;
	}
	return 1;
}

ll mxa = 0;
ll rho(ll n)
{ // skilar thaetti i |n|
	ll s[8] = {2, 3, 4, 5, 7, 11, 13, 1031}, i, j, a = 1;
   	lll x, y, d, m = n;
	while (1)
	{
		rep(j, 8)
		{
			x = y = s[j], d = 1;
			while (d == 1)
			{
				x = ((x*x)%m + a)%m;
				y = ((y*y)%m + a)%m;
				y = ((y*y)%m + a)%m;
				d = gcd(y < x ? x - y : y - x, n);
			}
			if (d != n) return d;
		}
		//printf("failed at %lld for a = %lld\n", n, a);
		if (++a > mxa) mxa = a;

		assert(a < 1000);
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
	ll s[200], ss = 0, p[] = {2, 3, 5, 7, 11, 13}, i;
	rep(i, sizeof(p)/sizeof(p[0])) while (n%p[i] == 0) n /= p[i], a[c++] = p[i];
	s[ss++] = n;
	if (n == 1) return;
	while (ss > 0)
	{
		ll k = s[--ss];
		if (miller_rabin(k, 10)) a[c++] = k;
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
	printf("The largest a so far is %lld\n", mxa);
	rep(i, c) if (!miller_rabin(a[i], 10))
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
		test(x);
		test(x*x);
		if (x*x*x < x*x) continue;
		test(x*x*x);
		if (x*x*x*x < x*x*x) continue;
		test(x*x*x*x);



#if 0
		rep(i, pp)
		{
			pollard_rho(p[i]*p[i]);
			printf("%lld*%lld is factored as: ", p[i], p[i]);
			rep(j, c) printf("%lld ", a[j]);
			printf("\n");
		}
#endif
	}
}

