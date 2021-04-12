#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)

int bs(int* a, int n, int t)
{
	int r = 0, s = n;
	while (r < s) (a[(r + s)/2] < t) ? (r = (r + s)/2 + 1) : (s = (r + s)/2);
	return r;
}

int lis(int* a, int n)
{
    int i, j;
    int b[n + 2];
	rep(i, n + 2) b[i] = INF;
    b[0] = -INF;
	rep(i, n) b[bs(b, n + 1, a[i])] = a[i];
    for (i = 0; b[i] != INF; i++);
    return i - 1;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	printf("Lengd lengstu vaxandi hlutruna listans er %d\n", lis(a, n));
	return 0;
}
