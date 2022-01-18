#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
	int x = *(int*)p1, y = *(int*)p2;
	return (x <= y) - (y <= x);
}

int rcmp(const void* p1, const void* p2)
{
	int x = *(int*)p1, y = *(int*)p2;
	return (x >= y) - (y >= x);
}

// raðar tölum í vaxandi og minnkandi röð
// 5
// 2 4 3 1 5
int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(a, n, sizeof *a, cmp);
	for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
	qsort(a, n, sizeof *a, rcmp);
	for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
	return 0;
}
