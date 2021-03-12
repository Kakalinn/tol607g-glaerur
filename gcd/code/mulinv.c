#include <stdio.h>
#include <assert.h>
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
	assert(g == 1);
	return x;
}

int main()
{
	ll a, b, m;
	scanf("%lld%lld", &a, &m);
	b = mulinv(a, m);
	assert(((a*b)%m + m)%m == 1);
	printf("%lld\n", b);
	return 0;
}
