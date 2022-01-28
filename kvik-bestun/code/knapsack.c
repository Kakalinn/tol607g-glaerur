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

void knapsack(int *v, int *w, int n, int c)
{
	int i, j, s[MAXN], ss;
	for (i = 0; i < n; i++) for (j = 0; j <= c; j++) d[i][j] = -1;
	for (i = 0; i < n; i++) a[i] = v[i], b[i] = w[i];
	j = c;
	ss = 0;
	for (i = n - 1; i >= 0; i--)
		if (dp_lookup(i - 1, j) < dp_lookup(i - 1, j - w[i]) + v[i])
			j -= w[i], s[ss++] = i;
	printf("%d\n", ss);
	for (i = 0; i < ss; i++) printf("%d ", s[i]);
	printf("\n");
}

int main()
{
	int n, c, i, j, v[MAXN], w[MAXN];
	while (scanf("%d%d", &c, &n) != EOF)
	{
		for (i = 0; i < n; i++) scanf("%d%d", &v[i], &w[i]);
		knapsack(v, w, n, c);
	}
	return 0;
}
