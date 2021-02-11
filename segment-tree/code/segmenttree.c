#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 2000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXN], o[MAXN], n;

void prop(int x, int y, int e)
{
	if (x == y) p[e] += o[e], o[e] = 0;
	else o[LEFT(e)] = o[RIGHT(e)] = o[e], o[e] = 0;
}

int query_(int i, int j, int x, int y, int e)
{
	prop(i, j, e);
	assert(o[e] == 0);
	if (x == i && y == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query_(i, m, x, y, LEFT(e));
	if (x > m && y > m) return query_(m + 1, j, x, y, RIGHT(e));
	return query_(i, m, x, m, LEFT(e)) + query_(m + 1, j, m + 1, y, RIGHT(e));
}
int query(int x, int y)
{
	return query_(0, n - 1, x, y, 1);
}

void rupdate_(int i, int j, int x, int y, int z, int e)
{
	prop(i, j, e);
	if (x == i && y == j) { o[e] = z; return; }
	int m = (i + j)/2;
	if (x <= m && y <= m) rupdate_(i, m, x, y, z, LEFT(e));
	else if (x > m && y > m) rupdate_(m + 1, j, x, y, z, RIGHT(e));
	else rupdate_(i, m, x, m, z, LEFT(e)), rupdate_(m + 1, j, m + 1, y, z, RIGHT(e));
}
// add z to all numbers in [x, y]
void rupdate(int x, int y, int z)
{
	rupdate_(0, n - 1, x, y, z, 1);
}

void update_(int i, int j, int x, int y, int e)
{
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) update_(i, m, x, y, LEFT(e));
		else update_(m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}
void update(int x, int y)
{
	return update_(0, n - 1, x, y, 1);
}

int slow(int* a, int l, int r)
{
	int x = 0;
	while (l < r) x += a[l++];
	return x;
}

int main() {
	srand(time(NULL));
	n = 10000;
	int i, q = 1000000, x, w, y, z;
	int a[n];
	for (i = 0; i < n; i++) a[i] = 0;
	for (i = 0; i < 4*n + 1; i++) p[i] = 0;
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + rand()%(n - x), y = rand()%(n*10), z = rand()%2;
		if (z) a[x] = y, update(x, a[x]);
		else if (query(x, w) != slow(a, x, w + 1)) break;
	}
	if (q != -1)
	{
		printf("[%d %d], %d %d\n", x, w, query(x, w), slow(a, x, w + 1));
		for (i = 0; i < n; i++) printf("%4d ", query(i, i)); printf("\n");
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
