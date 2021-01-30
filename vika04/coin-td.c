#include <stdio.h>
#define MAXN 10001
#define MAXM 10001
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int n, m, a[MAXM];
int d[MAXN];
int dp_lookup(int x)
{
	int i;
	if (x < 0) return INF; // Þessi lína þarf að vera fremst!
	if (d[x] != -1) return d[x];
	if (x == 0) return 0;
	d[x] = INF;
	for (i = 0; i < m; i++) d[x] = min(d[x], dp_lookup(x - a[i]) + 1);
	return d[x];
}

int main()
{
	int i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n + 1; i++) d[i] = -1;
	for (i = 0; i < m; i++) scanf("%d", &a[i]);
	printf("%d\n", dp_lookup(n));
	return 0;
}
