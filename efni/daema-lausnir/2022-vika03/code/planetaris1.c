#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
int cmp(const void* p1, const void* p2)
{
	int x = *(int*)p1, y = *(int*)p2;
	return (y <= x) - (x <= y);
}

int main()
{
    int i, n, a, e[MAXN];
	scanf("%d%d", &n, &a);
    for (i = 0; i < n; i++) scanf("%d", &e[i]);
    qsort(e, n, sizeof *e, cmp);
    for (i = 0; i < n; i++)
	{
		a -= e[i] + 1;
		if (a <= e[i] + 1) break;
	}
    printf("%d\n", i + 1);
	return 0;
}

