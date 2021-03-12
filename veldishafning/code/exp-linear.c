#include <stdio.h>
typedef long long ll;

int main()
{
	ll x, n, m, r = 1;
	scanf("%lld%lld%lld", &x, &n, &m);
	while (n-- != 0) r = (r*x)%m;
	printf("%lld\n", r);
	return 0;
}
