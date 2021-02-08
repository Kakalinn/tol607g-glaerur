#include <stdio.h>
#include <assert.h>
#define MAXN 18
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int a[MAXN][MAXN], d[MAXN][1 << MAXN], n;
int dp_lookup(int x, int y)
{
	int i;
	if (d[x][y] != -1) return d[x][y];
	if (y == 0) return a[x][0];
	d[x][y] = INF;
	for (i = 0; i < n; i++) if ((y&(1 << i)) != 0)
		d[x][y] = min(d[x][y], dp_lookup(i, y - (1 << i)) + a[x][i]);
	return d[x][y];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) for (j = 0; j < (1 << n); j++) d[i][j] = -1;
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
	printf("%d\n", dp_lookup(0, (1 << n) - 2));
	return 0;
}
