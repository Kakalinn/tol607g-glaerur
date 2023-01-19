#include <stdio.h>

int main()
{
	int n, k, i;
	scanf("%d%d", &n, &k);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));
	int b = 0, z = 0, mx = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == 0) z++;
		while (z > k)
		{
			if (a[b] == 0) z--;
			b++;
		}
		if (i - b + 1 > mx) mx = i - b + 1;
	}
	printf("%d\n", mx);
	return 0;
}
