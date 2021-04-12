#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)

int lis(int* a, int* t, int n)
{
    int i, j, r, x;
    int b[n + 2], c[n];
	rep(i, n + 2) b[i] = INF;
    b[0] = -INF;
	rep(i, n)
	{
		int r = 0, s = n;
		while (r < s) (b[(r + s)/2] < a[i]) ? (r = (r + s)/2 + 1) : (s = (r + s)/2);
		b[r] = a[i];
		c[i] = b[r - 1];
	}
	for (r = 0; b[r] != INF; r++);
	r--, j = 0;
	rep(i, n) if (a[i] >= a[j]) j = i;
	x = b[r];
	for (i = r - 1, j = n - 1; j >= 0; j--) if (a[j] == x) x = c[j], t[i--] = a[j];
	return r;
}

int issubseq(int* a, int n, int* b, int m)
{ // Is |b| a subsequence of |a|?
	if (n < m) return 0;
	int i, j = 0;
	rep(i, n) if (j < m && a[i] == b[j]) j++;
	return j == m;
}

int isinc(int* a, int n)
{ // Is |a| increasing?
	int i;
	rep(i, n - 1) if (a[i] > a[i + 1]) return 0;
	return 1;
}

int main()
{ // Test the LIS implementation. It assumes that the length it finds is correct, and tests the sequence.
	srand(time(NULL));
	int n = 100000, q = 10000000, i;
	int a[n], b[n], m;
	while (q--)
	{
		rep(i, n) a[i] = rand();
		m = lis(a, b, n);
		assert(isinc(b, m));
		assert(issubseq(a, n, b, m));
		//rep(i, m) printf("%d ", b[i]); printf("\n");
	}
	return 0;
}
