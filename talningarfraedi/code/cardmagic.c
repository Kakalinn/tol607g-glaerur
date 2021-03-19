#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MOD 1000000009
typedef long long ll;

ll d[101][5001], k;
ll dp_lookup(ll x, ll y)
{
	if (y < 0) return 0;
	if (d[x][y] != -1) return d[x][y];
	if (x == 0) return y == 0 ? 1 : 0;
	ll i;
	d[x][y] = 0;
	rep(i, k) d[x][y] = (d[x][y] + dp_lookup(x - 1, y - i - 1))%MOD;
	return d[x][y];
}

int main()
{
	ll n, m, i, j;
	scanf("%lld%lld%lld", &n, &k, &m);
	rep(i, 101) rep(j, 5001) d[i][j] = -1;
	printf("%lld\n", dp_lookup(n, m));
	return 0;
}
