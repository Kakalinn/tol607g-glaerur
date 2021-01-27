#include <stdio.h>
#define SWAP(E, F) { int swap = (E); (E) = (F); (F) = swap; }
int perm(int* a, int n, int x)
{
	int i;
	if (x == n)
	{
		for (i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) break;
		return i < n - 1 ? 0 : 1;
	}
	for (i = x; i < n; i++)
	{
		SWAP(a[x], a[i]);
		if (perm(a, n, x + 1)) return 1;
		SWAP(a[x], a[i]);
	}
	return 0;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	perm(a, n, 0);
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
