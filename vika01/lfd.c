#include <stdio.h>

int main()
{
	int i, t, n, r;
	scanf("%d", &t);
	while (t-- != 0)
	{
		scanf("%d", &n);
		r = 1;
		for (i = 1; i <= n; ++i)
		{
			r *= i;
			r %= 10;
		}
		printf("%d\n", r);
	}
	return 0;
}
