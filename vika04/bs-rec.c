#include <stdio.h>

int bs(int* a, int t, int l, int r)
{
	if (r - l == 1) return a[l] == t ? l : -1;
	int m = (l + r)/2;
	if (a[m] <= t) return bs(a, t, m, r);
	else return bs(a, t, l, m);
}

int main()
{
	int i, n, q, x;
	scanf("%d%d", &n, &q);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	while (q-- != 0)
	{
		scanf("%d", &x);
		printf("%d\n", bs(a, x, 0, n));
	}
	return 0;
}
