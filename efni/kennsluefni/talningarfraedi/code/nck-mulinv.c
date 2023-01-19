#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 1000000
typedef long long ll;

void swap(ll* x, ll* y) { ll s = *x; *x = *y; *y = s; }
ll egcd(ll a, ll b, ll* x, ll* y)
{
	if (b == 0)
	{
		*x = 1, *y = 0;
		return a;
	}
	ll r = egcd(b, a%b, x, y);
	*x -= a/b*(*y);
	swap(x, y);
	return r;
}

ll mulinv(ll a, ll m)
{
	ll x, y, g;
	g = egcd(a, m, &x, &y);
	return x;
}

ll f[MAXN], fm[MAXN];
ll prepare_nck(ll m)
{ // Her tharf |m| ad vera frumtala.
	ll i;
	f[0] = 1;
	rep(i, MAXN) if (i != 0) f[i] = (f[i - 1]*i)%m;
	rep(i, MAXN) fm[i] = mulinv(f[i], m);
}

ll nck(ll n, ll k, ll m)
{
	return (((f[n]*fm[n - k])%m)*fm[k])%m;
}

int main()
{
	ll n, k, m;
	scanf("%lld%lld%lld", &n, &k, &m);
	prepare_nck(m);
	printf("%lld\n", nck(n, k, m));
}
