#include <stdio.h>
#include <string.h>
#define MAXN 1001
#define MAXC 1001
int max(int a, int b) { if (a < b) return b; return a; }

int d[MAXN][MAXC], b[MAXN];
int dp_lookup(int x, int y)
{
	if (x < 0 && y == 0) return 1;
	if (y < 0 || x < 0) return 0;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = dp_lookup(x - 1, y) || dp_lookup(x - 1, y - b[x]);
}

int subsetsum(int *a, int n, int c)
{
	int i, j;
	for (i = 0; i < n; i++) for (j = 0; j < c + 1; j++) d[i][j] = -1;
	for (i = 0; i < n; i++) b[i] = a[i];
	while (!dp_lookup(n - 1, c)) c--;
	return c;
}

int main()
{
	int n, c, i, j;
	scanf("%d%d", &n, &c);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d\n", subsetsum(a, n, c));
	return 0;
}
