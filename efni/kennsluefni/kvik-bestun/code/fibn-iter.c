#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	a[0] = a[1] = 1;
	for (i = 2; i < n; i++) a[i] = a[i - 1] + a[i - 2];
	printf("%d\n", a[n - 1]);
	return 0;
}
