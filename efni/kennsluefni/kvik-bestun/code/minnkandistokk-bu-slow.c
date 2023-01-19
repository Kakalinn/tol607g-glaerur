#include <stdio.h>
#include <assert.h>
typedef long long ll;
#define MAXN 3001
#define INF (1LL << 60)
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

int main()
{
	ll i, j, k, n;
	scanf("%lld", &n);
	ll d[n][n], a[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) d[i][j] = -INF;
	d[n - 1][1] = a[n - 1];
	for (i = n - 2; i >= 0; i--) d[i][1] = d[i + 1][1] + a[i];
	for (i = 0; i < n; i++) d[n - 1][i] = a[n - 1];
	for (j = 2; j < n; j++)
		for (i = n - 2; i >= 0; i--)
			for (k = 1; k < min(j + 1, n - i); k++)
				d[i][j] = max(d[i][j], d[i + k][k] + a[i]);
	printf("%lld\n", d[0][n - 1]);
	return 0;
}
