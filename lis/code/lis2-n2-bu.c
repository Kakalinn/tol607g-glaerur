#include <stdio.h>
#include <string.h>
#define MAXN 1001
int min(int a, int b) { return a > b ? b : a; }

int lis(int *a, int *b, int n)
{
	int i, j, x, y;
	int d[n + 1][n + 1];
	for (i = 0; i < n + 1; i++) d[0][i] = (1 << 30);
	for (i = 0; i < n + 1; i++) d[i][0] = -(1 << 30);
	for (i = 1; i < n + 1; i++)
	{
		for (j = 0; j < n + 1; j++)
		{
			if (a[i - 1] < d[i - 1][j - 1]) d[i][j] = d[i - 1][j];
			else d[i][j] = min(d[i - 1][j], a[i - 1]);
		}
		for (int ii = 0; ii < n + 1; ii++) { for (int jj = 0; jj < n + 1; jj++) printf("%10d ", d[ii][jj]); printf("\n"); }
		printf("\n\n");
	}
	for (x = n; d[n][x] > n; x--);
	for (i = 0; i < x; i++) b[i] = d[n - x + i + 1][i + 1];
	return x;
}

int main()
{
	int n, m, i, j, x, l;
	scanf("%d", &n);
	int a[n], b[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	l = lis(a, b, n);

	printf("Lend lengstu vaxandi hlutruna er %d\n", l);
	for (i = 0; i < l; i++) printf("%d ", b[i]);
	printf("\n");

	return 0;
}
