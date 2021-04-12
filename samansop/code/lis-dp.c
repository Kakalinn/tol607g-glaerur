#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 10000
int max(int a, int b) { return a < b ? b : a; }

int a[MAXN], d[MAXN], n;
int dp_lookup(int x)
{
	int i;
	if (d[x] != -1) return d[x];
	d[x] = 1;
	rep(i, x) if (a[i] <= a[x])
		d[x] = max(d[x], 1 + dp_lookup(i));
	return d[x];
}

int main()
{
	int i, j;
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) d[i] = -1;
	rep(i, n) printf("%3d ", a[i]); printf("\n");
	rep(i, n) printf("%3d ", dp_lookup(i)); printf("\n");
	return 0;
}
