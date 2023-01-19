#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>
typedef long long ll;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd(b, a%b);
}

ll slow_gcd(ll a, ll b)
{
	if (a == b) return a;
	if (a > b) return gcd(b, a);
	return gcd(a, b - a);
}

int main()
{
	srand(time(NULL));
	ll x, y, q = 1000000000;
	while (q-- != 0)
	{
		x = rand(), y = rand();
		if (x > y) { ll a = x; x = y; y = a; }
		assert(gcd(x, y) == gcd(x, y - x));
	}
	return 0;
}
