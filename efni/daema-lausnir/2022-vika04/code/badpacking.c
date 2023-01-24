#include <stdlib.h>
#include <stdio.h>
#define MAXN 1000
#define MAXC 100001
#define CMP(E, F) (((F) <= (E)) - ((E) <= (F)))
int cmp(const void *p1, const void *p2)
{
	return -CMP(*(int*)p1, *(int*)p2);
}

int d[MAXN][MAXC], a[MAXN];
int dp_lookup(int x, int y)
{
	if (x < 0 || y < 0) return !y;
	if (d[x][y] != -1) return d[x][y];
	return d[x][y] = dp_lookup(x - 1, y) || dp_lookup(x - 1, y - a[x]);
}

int main()
{
	int i, j, t, n, c;
	scanf("%d%d", &n, &c);
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) for (j = 0; j < c + 1; j++) d[i][j] = -1;
	qsort(a, n, sizeof *a, cmp);
	for (i = 0; i < c + 1; i++)
	{
		for (t = 0, j = n - 1; j >= 0; j--)
		{
			if (a[j] > c - i) break;
			t += a[j];
		}
		if (t <= i && dp_lookup(j, i - t)) break;
	}
	printf("%d\n", i);
	return 0;
}
