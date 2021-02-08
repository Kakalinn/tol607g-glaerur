#include <stdio.h>
#define MAXN 10001
#define MAXM 10001
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int n, m, a[MAXM];
int d[MAXN][MAXM];
int dp_lookup(int x, int y)
{
	if (x < 0) return INF;
	if (d[x][y] != -1) return d[x][y];
	if (y == m) return x == 0 ? 0 : INF;
	return d[x][y] = min(dp_lookup(x, y + 1),
							dp_lookup(x - a[y], y + 1) + 1);
}

int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	printf("%d\n", dp_lookup(n, 0));
	for (i = 0; i < n + 1; i++)
		printf("%3d ", dp_lookup(i, 0) == INF ? -1 : dp_lookup(i, 0));
	printf("\n");
	return 0;
}
