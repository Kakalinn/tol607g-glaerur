#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 10000
typedef long long ll;

ll d[MAXN][MAXN], m;
ll dp_lookup(ll x, ll y)
{
	if (x < 0 || y < 0 || y > x) return 0;
	if (d[x][y] != -1) return d[x][y];
	if (y == 0 || y == x) return 1;
	return d[x][y] = (dp_lookup(x - 1, y - 1) + dp_lookup(x - 1, y))%m;
}

int main()
{
	ll i, j, n;
	scanf("%lld%lld", &n, &m);
	rep(i, MAXN) rep(j, MAXN) d[i][j] = -1;
	rep(i, n)
	{
		rep(j, n - 1 - i) printf("   ");
		rep(j, i + 1) printf("%5lld ", dp_lookup(i, j));
		printf("\n");
	}
}
