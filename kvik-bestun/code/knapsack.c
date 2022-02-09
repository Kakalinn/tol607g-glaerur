#include <stdio.h>
#include <assert.h>
#define MAXN 2001
#define MAXC 2001
#define INF (1 << 30)
int max(int a, int b) { if (a > b) return a; return b; }

int d[MAXN][MAXC], a[MAXN], b[MAXN];
int dp_lookup(int x, int y)
{
	if (y < 0) return -INF;
	if (x < 0) return 0;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = max(dp_lookup(x - 1, y),
							dp_lookup(x - 1, y - b[x]) + a[x]);
}

void knapsack(int *v, int *w, int *r, int n, int c)
{
	int i, j, s[MAXN], ss;
	for (i = 0; i < n; i++) for (j = 0; j <= c; j++) d[i][j] = -1;
	for (i = 0; i < n; i++) a[i] = v[i], b[i] = w[i], r[i] = 0;
	j = c;
	for (i = n - 1; i >= 0; i--)
		if (dp_lookup(i - 1, j) < dp_lookup(i - 1, j - w[i]) + v[i])
			j -= w[i], r[i] = 1;
}

int main()
{
	int k, n, c, i, j, v[MAXN], w[MAXN], r[MAXN];
	scanf("%d%d", &c, &n);
	for (i = 0; i < n; i++) scanf("%d%d", &v[i], &w[i]);
	knapsack(v, w, r, n, c);
	for (k = i = 0; i < n; i++) k += r[i];
	printf("%d\n", k);
	for (i = 0; i < n; i++) if (r[i]) printf("%d ", i + 1);
	printf("\n");
	return 0;
}
