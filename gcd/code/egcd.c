#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

int main()
{
	srand(time(NULL));
	ll a, b, x, y, g, q = 1000000000;
	while (q-- != 0)
	{
		a = rand()%100, b = rand()%100;
		g = egcd(a, b, &x, &y);
		assert(a*x + b*y == g)
	}
	return 0;
}
