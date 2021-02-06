#include <stdio.h>
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int main()
{
	int i, j, n, m, x;
	scanf("%d%d", &n, &m);
	int d[n + 1], a[m];
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	for (i = 0; i < n + 1; i++) d[i] = INF;
	d[0] = 0;
	for (i = 0; i < m; i++)
		for (j = 0; j < n + 1 - a[i]; j++)
			if (d[j] < INF && d[j + a[i]] > d[j] + 1)
	{
		d[j + a[i]] = d[j] + 1;

	}

	printf("%d\n", d[n]);







	return 0;
}
