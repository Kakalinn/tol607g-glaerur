#include <stdio.h>
#include <stdlib.h>

int cmp(const void* p1, const void* p2)                                         // Samanburðarfall fyrir vaxandi röðun.
{
	int x = *(int*)p1, y = *(int*)p2;
	return (x <= y) - (y <= x);
}

int rcmp(const void* p1, const void* p2)                                        // Samanburðarfall fyrir minnkandi röðun.
{
	int x = *(int*)p1, y = *(int*)p2;
	return (x >= y) - (y >= x);
}

int main()
{
	int n, i;
	scanf("%d", &n);                                                            // Les inn fjölda talna sem á að raða.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Les inn tölurnar sem á að raða.
	qsort(a, n, sizeof *a, cmp);                                                // Raðar í vaxandi röð.
	for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");                  // Prentar listann.
	qsort(a, n, sizeof *a, rcmp);                                               // Raðar í minnkandi röð.
	for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");                  // Prentar listann.
	return 0;
}
// Forrit sem raðar tölum í vaxandi og minnkandi röð
// Dæmi um inntak:
// 5
// 2 4 3 1 5
