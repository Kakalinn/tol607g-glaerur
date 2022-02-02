#include <stdio.h>

int main()
{
	int i, n, r;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (r = i = 0; i < n; i++) if (a[i] > a[r]) r = i;
	printf("%d %d\n", r, r);
	return 0;
}
