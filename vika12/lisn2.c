#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int a[n], c[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(a[i]));
	}
	for (i = 0; i < n; i++)
	{
		c[i] = 1;
		for (j = 0; j < i; j++)
		{
			if (a[i] > a[j] && c[i] < c[j] + 1)
			{
				c[i] = c[j] + 1;
			}
		}
	}
	for (i = 0; i < n; i++) printf("%4d", a[i]); printf("\n");
	for (i = 0; i < n; i++) printf("%4d", c[i]); printf("\n");
}
