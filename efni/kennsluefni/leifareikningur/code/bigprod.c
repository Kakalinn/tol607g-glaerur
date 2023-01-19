#include <stdio.h>
typedef long long ll;
typedef __int128 lll;

ll bigprod(ll x, ll y, ll m)
{
	return ((lll)x*y)%m;
}


//profid thetta input:
//  9223372036854775807 9223372036854775807 9223372036854775801
int main()
{
	ll x, y, m;
	scanf("%lld%lld%lld", &x, &y, &m);
	printf("%lld\n", (x*y)%m);
	printf("%lld\n", bigprod(x, y, m));
}
