#include <stdio.h>
#define MAXN 100000
typedef long long ll;

int main()
{
	ll i, n, w, r, s, t = 0, a[MAXN];
	scanf("%lld%lld", &n, &w);
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (i = 0; i < n; i++) t += a[i];
	r = 1, s = 1000000001;
	while (r < s)
	{
		ll m = (r + s)/2, z = 0;
		for (i = 0; i < n; i++) z += (a[i] + m - 1)/m;
		if (z > w) r = m + 1;
		else s = m;
	}
	printf("%lld\n", w*r - t);
	return 0;
}
