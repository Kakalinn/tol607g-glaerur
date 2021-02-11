// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 2000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
void update(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) update(p, i, m, x, y, LEFT(e));
		else update(p, m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}

int queryl(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryl(p, i, m, x, LEFT(e)) + p[RIGHT(e)])
                    : (queryl(p, m + 1, j, x, RIGHT(e)));
}

int queryr(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryr(p, i, m, x, LEFT(e)))
                    : (p[LEFT(e)] + queryr(p, m + 1, j, x, RIGHT(e)));
}

int query(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query(p, i, m, x, y, LEFT(e));
	if (x > m && y > m) return query(p, m + 1, j, x, y, RIGHT(e));
	return queryl(p, i, m, x, LEFT(e)) + queryr(p, m + 1, j, y, RIGHT(e));
}

void prop(int* p, int i, int j, int x, int e)
{
	if (i == j) return;
	...
}

int slow(int* a, int l, int r)
{
	int x = 0;
	while (l < r) x += a[l++];
	return x;
}

int main() {
	srand(time(NULL));
	int i, n = 1000, q = 1000000, x, w, y, z;
	int a[n], p[4*n + 1];
	for (i = 0; i < n; i++) a[i] = 0;
	for (i = 0; i < 4*n + 1; i++) p[i] = 0;
	while (q-- != 0)
	{
		x = rand()%n, w = x + rand()%(n - x), y = rand()%(n*10), z = rand()%2;
		if (z) a[x] = y, update(p, 0, n - 1, x, a[x], 1);
		else if (query(p, 0, n - 1, x, w, 1) != slow(a, x, w + 1)) break;
	}
	if (q != -1)
	{
		printf("[%d %d], %d %d\n", x, w + 1, query(p, 0, n - 1, x, w + 1, 1), slow(a, x, w + 1));
		//for (i = 0; i < n; i++) printf("%4d ", query(i, i + 1)); printf("\n");
		for (i = 0; i < n; i++) printf("%4d ", a[i]); printf("\n");
		for (i = 0; i < n; i++)
		{
			if (i == x) printf("[    ");
			else if (i == w + 2) printf("]    ");
			else printf("     ");
		}
		if (w + 1 == i) printf("]\n");
		else printf("\n");
	}
	return 0;
}
