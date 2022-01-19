#include <stdio.h>

int len(int n, int k)
{
	int r = 0;
	while (n > 0) r++, n /= k;
	return r;
}

int main()
{
	int i, j, n, r = 0;
	scanf("%d", &n);
	for (i = 2; i <= n; i++) r += len(n, i);
	printf("%d\n", r);
	return 0;
}
