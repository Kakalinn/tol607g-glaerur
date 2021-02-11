#include <stdio.h>
int main()
{
	int n, m, i, x, y, z, k = 1;
	scanf("%d%d", &n, &m);
	while (k*k < n) k++;
	int a[n], b[k];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));
	for (i = k; i < k; i++) b[i] = 0;
	for (i = 0; i < n; i++) b[i/k] += a[i];
	while (m-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1)
		{
			b[y/k] = b[y/k] - a[y] + z;
			a[y] = z;
		}
		if (x == 2)
		{
			int r = 0, k1 = y/k, k2 = z/k;
			if (k2 - k1 < 2) for (i = y; i <= z; i++) r += a[i];
			else
			{
				while (y/k == k1) r += a[y++];
				while (z/k == k2) r += a[z--];
				for (i = k1 + 1; i < k2; i++) r += b[i];
			}
			printf("%d\n", r);
		}
	}
	return 0;
}
