#include <stdio.h>
#include <string.h>
#define MAXN 1001
int min(int a, int b) { return a > b ? b : a; }

int v[MAXN], d[MAXN][MAXN];
int dp_lookup(int x, int y)
{
	if (x == -1) return y == 0 ? -(1 << 30) : (1 << 30);
	if (d[x][y] != -1) return d[x][y];
	if (v[x] < dp_lookup(x - 1, y - 1)) return d[x][y] = dp_lookup(x - 1, y);
	return d[x][y] = min(dp_lookup(x - 1, y), v[x]);
}

int lis(int *a, int n)
{
	int i, j, x;
	for (i = 0; i < n; i++) v[i] = a[i];
	for (i = 0; i < n; i++) for (j = 0; j < n + 1; j++) d[i][j] = -1;
	for (x = n; dp_lookup(n - 1, x) == (1 << 30); x--);
	return x;
}

int main()
{
	int n, m, i, j, x;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d\n", lis(a, n));
	return 0;
}
