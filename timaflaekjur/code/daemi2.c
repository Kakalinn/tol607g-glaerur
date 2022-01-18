#include <stdio.h>

int main()
{
	int i, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		r += i;
	printf("%d\n", r);
	return 0;
}
