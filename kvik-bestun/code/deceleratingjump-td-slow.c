#include <stdio.h>
typedef long long ll;
#define MAXN 3001
#define INF (1LL << 60)
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

ll d[MAXN][MAXN], a[MAXN], n;
ll dp_lookup(ll x, ll y)
{
	ll i;
	if (x == n - 1) return a[x];
	if (d[x][y] != -INF) return d[x][y];
	for (i = 1; i < min(y + 1, n - x); i++)
		d[x][y] = max(d[x][y], dp_lookup(x + i, i));
	return d[x][y] = d[x][y] + a[x];
}

int main()
{
	ll i, j;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) d[i][j] = -INF;
	printf("%lld\n", dp_lookup(0, n - 1));
	return 0;
}
