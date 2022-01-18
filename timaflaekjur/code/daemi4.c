#include <stdio.h>

int main()
{
	int i, j, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	for (j = 0; j < i/2; j++)
		r += i^j;
	printf("%d\n", r);
	return 0;
}
