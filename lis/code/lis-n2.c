#include <stdio.h>
#include <string.h>
#define MAXN 1001
int max(int a, int b) { return a < b ? b : a; }

int v[MAXN], d[MAXN];
int dp_lookup(int x)
{
	if (d[x] != -1) return d[x];
	if (x == 0) return 1;
	int i;
	for (d[x] = 1, i = 0; i < x; i++) if (v[i] <= v[x])
		d[x] = max(d[x], dp_lookup(i) + 1);
	return d[x];
}

int lis(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++) d[i] = -1, v[i] = a[i];
	return dp_lookup(n - 1);
}

int main()
{
	int n, m, i, j;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	printf("%d\n", lis(a, n));
	return 0;
}
