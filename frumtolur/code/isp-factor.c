#include <stdio.h>
typedef long long ll;

int factor(ll x)
{
	ll i;
	for (i = 2; i*i <= x;)
	{
		if (x%i == 0) printf("%lld ", i), x /= i;
		else i++;
	}
	if (x != 1) printf("%lld ", x);
	printf("\n");
	return 1;
}

int main()
{
	ll x;
	scanf("%lld", &x);
	factor(x);
}
 
