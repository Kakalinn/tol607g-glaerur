#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 10000000
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
typedef __int128 lll;

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
	ll i, k, s = 0, d = n - 1,
	   	t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
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

ll foo(ll a, ll b)
{
	return rand()%(b - a) + a;
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	ll x = 1, a, b;
	if (argc == 1) scanf("%lld%lld", &a, &b);
	else if (argc == 2) a = 2, scanf("%lld", &b);
	else a = atoll(argv[1]), b = atoll(argv[2]);
	while (!miller_rabin(x)) x = foo(a, b);
	printf("%lld\n", x);
}
