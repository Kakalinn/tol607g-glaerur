#include <stdio.h>

int greedy_check(int *x, int n, int k, int m)
{
	int i, j, r = 0;
	for (i = 0, j = -2*m; i < n; i++) if (x[i] >= j) j = x[i] + m, r++;
	return r >= k;
}

int main()
{
	int i, r, s, n, k;
	scanf("%d%d", &n, &k);
	int x[n];
	for (i = 0; i < n; i++) scanf("%d", &x[i]);
	r = 0, s = 1000000000;
	while (r < s)
	{
		int m = (r + s)/2;
		if (greedy_check(x, n, k, m)) r = m + 1;
		else s = m;
	}
	printf("%d\n", r - 1);
	return 0;
}
