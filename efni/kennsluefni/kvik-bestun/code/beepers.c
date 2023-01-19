#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#define MAXN 18
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int g[MAXN][MAXN], d[MAXN][1 << MAXN], m;
int dp_lookup(int x, int y)
{
	int i;
	if (d[x][y] != -1) return d[x][y];
	if (x == 0 && y != 0) return (y == ((1 << n) - 1)) ? 0 : INF;
	for (d[x][y] = INF, i = 0; i < n; i++) if ((y&(1 << i)) == 0)
		d[x][y] = min(d[x][y], dp_lookup(i, y + (1 << i)) + g[x][i]);
	return d[x][y];
}

int tsp(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++) for (j = 0; j < (1 << n); j++) d[i][j] = -1;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) g[i][j] = a[i*MAXN + j];
	return dp_lookup(0, 0);
}

int main()
{
	int i, j, t, n, xx, yy, x[MAXN], y[MAXN], a[MAXN][MAXN];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &xx, &yy);
		scanf("%d%d", &x[0], &y[0]);
		scanf("%d", &n);
		n++;
		for (i = 1; i < n; i++) scanf("%d%d", &x[i], &y[i]);
		for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		printf("%d\n", tsp(*a, n));
	}
	return 0;
}
