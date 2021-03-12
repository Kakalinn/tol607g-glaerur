#include <stdio.h>
typedef long long ll;

ll modpow(ll x, ll n, ll m)
{
	if (n == 0) return 1;
	ll r = modpow(x, n/2, m);
	r = (r*r)%m;
	return n%2 == 0 ? r : (r*x)%m;
}

int main()
{
	ll x, n, m, r = 1;
	scanf("%lld%lld%lld", &x, &n, &m);
	printf("%lld\n", modpow(x, n, m));
	return 0;
}
