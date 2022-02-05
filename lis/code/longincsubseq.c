#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define INF (1 << 30)
#define MAXN 1001
int max(int a, int b) { return a < b ? b : a; }

int lis(int *a, int *b, int n)
{
	int i, j, x, y;
	int d[n + 1], e[n];
	for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;
	for (i = 0; i < n; i++)
	{
		int r = 0, s = n + 1;
		while (r < s)
		{
			int m = (r + s)/2;
			if (d[m] < a[i]) r = m + 1;
			else s = m;
		}
		d[r] = a[i], e[i] = d[r - 1];
	}
	for (x = n; d[x] == INF; x--);
	for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (a[i] == y)
		y = e[i], b[j--] = i;
	return x;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	while (1)
	{
		int a[n], b[n];
		for (i = 0; i < n; i++) scanf("%d", &a[i]);
		int l = lis(a, b, n);
		printf("%d\n", l);
		for (i = 0; i < l; i++) printf("%d ", b[i]);
		printf("\n");
		if (scanf("%d", &n) == EOF) break;
	}
	return 0;
}
