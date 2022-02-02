#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define MAXN 1001
int max(int a, int b) { return a < b ? b : a; }

int lis(int *a, int *b, int n)
{
	int i, j, x, y;
	int d[n + 1], e[n];
	for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -(1 << 30) : (1 << 30);
	for (i = 0; i < n; i++)
	{
		int r = 0, s = n + 1;
		while (r < s)
		{
			int m = (r + s)/2;
			if (d[m] <= a[i]) r = m + 1;
			else s = m;
		}
		d[r] = a[i], e[i] = d[r - 1];
	}
	for (x = n; d[x] == (1 << 30); x--);
	for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--)
		if (a[i] == y) y = e[i], b[j--] = a[i];
	return x;
}

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

int dp_lis(int *a, int n)
{
	int i, r = 1;
	for (i = 0; i < n; i++) d[i] = -1, v[i] = a[i];
	for (i = 0; i < n; i++) r = max(r, dp_lookup(i));
	return r;
}

void shuffle(int *a, int m, int n)
{
	int i, j, s;
	for (i = 0; i < m; i++)
	{
		j = i + rand()%(n - i);
		s = a[j]; a[j] = a[i]; a[i] = s;
	}
}

int issubseq(int* a, int n, int* b, int m)
{ // Is |b| a subsequence of |a|?
	if (n < m) return 0;
	int i, j = 0;
	for (i = 0; i < n; i++) if (j < m && a[i] == b[j]) j++;
	return j == m;
}

int isinc(int* a, int n)
{ // Is |a| increasing?
	int i;
	for (i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) return 0;
	return 1;
}

void check_random(int n)
{
	int i, l, a[n], b[n];
	for (i = 0; i < n; i++) a[i] = (i/2)*4;
	shuffle(a, n, n);
	assert(dp_lis(a, n) == (l = lis(a, b, n)));
	assert(issubseq(a, n, b, l));
	assert(isinc(b, l));
}

int main()
{
	srand(time(NULL));
	int q = 1000000, n, m, i, j, x, l;
#if 0
	scanf("%d", &n);
	int a[n], b[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	l = lis(a, b, n);

	printf("Lend lengstu vaxandi hlutruna er %d\n", l);
	for (i = 0; i < l; i++) printf("%d ", b[i]);
	printf("\n");
#else
	while (q--) check_random(1000);
#endif
	return 0;
}
