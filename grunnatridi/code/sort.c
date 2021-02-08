#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)
{
	return *(int*)p1 - *(int*)p2;
}

int rcmp(const void* p1, const void* p2)
{
	return *(int*)p2 - *(int*)p1;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);

	qsort(a, n, sizeof(a[0]), cmp);

	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");

	qsort(a, n, sizeof(a[0]), rcmp);
	
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");

	return 0;
}
