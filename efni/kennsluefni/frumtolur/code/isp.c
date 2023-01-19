#include <stdio.h>
typedef long long ll;

int isp(ll x)
{
	ll i;
	if (x <= 1) return 0;
	for (i = 2; i*i <= x; i++) if (x%i == 0) return 0;
	return 1;
}

int main()
{
	ll x;
	while (scanf("%lld", &x) != EOF)
	{
		if (isp(x)) printf("%lld\n", x);
		else fprintf(stderr, ">> %lld is not a prime\n", x);
	}
}
 
