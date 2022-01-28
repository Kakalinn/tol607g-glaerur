#include <stdio.h>
#include <string.h>
#define MAXN 101
#define MAXC 100001
int max(int a, int b) { if (a < b) return b; return a; }

int d[MAXN][MAXC], b[MAXN];
int dp_lookup(int x, int y)
{
	if (x < 0 && y == 0) return 1;
	if (y < 0 || x < 0) return 0;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = dp_lookup(x - 1, y) || dp_lookup(x - 1, y - b[x]);
}

void partition(int *a, int *r, int n)
{
	int i, j, t = 0, c;
	for (i = 0; i < n; i++) t += a[i], r[i] = 0, b[i] = a[i];
	c = t/2;
	for (i = 0; i < n; i++) for (j = 0; j < c + 1; j++) d[i][j] = -1;
	while (!dp_lookup(n - 1, c)) c--;
	i = n - 1, j = c;
	while (i > 0 && j > 0)
	{
		if (dp_lookup(i - 1, j) > dp_lookup(i - 1, j - a[i])) i--;
		else r[i] = 1, j -= a[i], i--;
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int a[n], r[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	partition(a, r, n);
	printf("Fyrri hópur: ");
	for (i = 0; i < n; i++) if (r[i]) printf(" %2d", a[i]);
	printf("\n");
	printf("Seinni hópur:");
	for (i = 0; i < n; i++) if (!r[i]) printf(" %2d", a[i]);
	printf("\n");
	return 0;
}
