#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXN], o[MAXN], n;

void prop(int x, int y, int e) //Hjálparfall
{ // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
	p[e] += (y - x + 1)*o[e];   
	if (x != y) o[LEFT(e)] += o[e], o[RIGHT(e)] += o[e];
	o[e] = 0;
}
int query_rec(int i, int j, int x, int y, int e)
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query_rec(i, m, x, y, LEFT(e));
	else if (x > m && y > m) return query_rec(m + 1, j, x, y, RIGHT(e));
	return query_rec(i, m, x, m, LEFT(e))
			+ query_rec(m + 1, j, m + 1, y, RIGHT(e));
}
int query(int x, int y)
{ // Finnum summuna yfir [x, y].
	return query_rec(0, n - 1, x, y, 1);
}
void update_rec(int i, int j, int x, int y, int z, int e)
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) { o[e] = z; return; }
	int m = (i + j)/2;
	p[e] += (y - x + 1)*z;
	if (x <= m && y <= m) update_rec(i, m, x, y, z, LEFT(e));
	else if (x > m && y > m) update_rec(m + 1, j, x, y, z, RIGHT(e));
	else update_rec(i, m, x, m, z, LEFT(e)),
		   update_rec(m + 1, j, m + 1, y, z, RIGHT(e));
}
void update(int x, int y, int z)
{ // Bætum z við stökin á bilinu [x, y]
	update_rec(0, n - 1, x, y, z, 1);
}

int slow(int* a, int l, int r)
{
	int x = 0;
	while (l <= r) x += a[l++];
	return x;
}

int main()
{
	srand(time(NULL));
	int i, q = 1000000, x, w, y, z;
	n = 10000;
	int b[n];
	for (i = 0; i < n; i++) b[i] = 0;
	for (i = 0; i < 5*n; i++) p[i] = o[i] = 0;
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + rand()%(n - x), y = rand()%(n*10), z = rand()%2;
		if (z)
		{
			update(x, w, y);
			for (i = x; i <= w; i++) b[i] += y;
		}
		else if (query(x, w) != slow(b, x, w)) break;
	}
	assert(q == -1);
	if (q != -1)
	{
		// this is if it fails
		printf("[%d %d], %d %d\n", x, w, query(x, w), slow(b, x, w));
		for (i = 0; i < n; i++) printf("%4d ", query(i, i)); printf("\n");
		for (i = 0; i < n; i++) printf("%4d ", b[i]); printf("\n");
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
