#include <stdio.h>
void perm(int* a, int* f, int n, int x)
{
	int i;
	if (x == n)
	{
		for (i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < n; i++) if (f[i] == 0)
	{
		f[i] = 1;
		a[x] = i + 1;
		perm(a, f, n, x + 1);
		f[i] = 0;
	}
}

int main()
{
	int i, n;
	scanf("%d", &n);
	int a[n], f[n];
	for (i = 0; i < n; i++) f[i] = 0;
	perm(a, f, n, 0);
}
