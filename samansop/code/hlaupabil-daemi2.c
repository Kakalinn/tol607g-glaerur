#include <stdlib.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef struct { int x, y; } ii;
int cmp(const void* p1, const void* p2) { return ((ii*)p1)->x - ((ii*)p2)->x; }

int main()
{
	int n, r, i, j, k;
	scanf("%d", &n);
	ii a[2*n]; int b[n];
	rep(i, n)
	{
		scanf("%d%d", &(a[2*i].x), &(a[2*i + 1].x));
		a[2*i].y = i; a[2*i + 1].y = i; b[i] = 0;
	}
	qsort(a, 2*n, sizeof(a[0]), cmp);
	i = 0, r = 0;
	while (i < 2*n)
	{
		k = 1, j = i + 1, b[a[i].y] = 1;
		while (k > 0)
		{
			if (b[a[j].y] == 1) k--;
			else b[a[j].y] = 1, k++;
			j++;
		}
		r = r + a[j - 1].x - a[i].x; i = j;
	}
	printf("%d\n", r);
	return 0;
}
