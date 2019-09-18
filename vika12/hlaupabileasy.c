#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int x, y;
} par;

int cmp(const void* p1, const void* p2)
{
	return ((par*)p1)->x - ((par*)p2)->x;
}

int main()
{
	int n, r, i, j, k;
	scanf("%d", &n);
	par a[2*n]; int b[n];
	for (i = 0; i < n; i++)
	{
		b[i] = 0;
		scanf("%d %d", &(a[2*i].x), &(a[2*i + 1].x));
		a[2*i].y = i;
		a[2*i + 1].y = i;
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
		r = r + a[j - 1].x - a[i].x;
		i = j;
	}

	printf("%d\n", r);
}
