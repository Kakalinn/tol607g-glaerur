#include <stdio.h>
#define SWAP(E, F) { int swap = (E); (E) = (F); (F) = swap; }
void perm(int* a, int n, int x)
{
	int i;
	if (x == n)
	{
		for (i = 0; i < n; i++) printf("%d ", a[i]);
		printf("\n");
		return;
	}
	for (i = x; i < n; i++)
	{
		SWAP(a[x], a[i]);
		perm(a, n, x + 1);
		SWAP(a[x], a[i]);
	}
	return;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) a[i] = i + 1;
	perm(a, n, 0);
	return 0;
}
