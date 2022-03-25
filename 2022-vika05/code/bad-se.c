#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXN*5], n;
int qrec(int i, int j, int x, int y, int e) // Hjálparfall.
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	if (x == i && y == j) return p[e];
	int m = (i + j)/2;
	if (y <= m) return qrec(i, m, x, y, LEFT(e));
	if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));
	return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
}
int query(int x, int y) { return qrec(0, n - 1, x, y, 1); }
void urec(int i, int j, int x, int y, int e) // Hjálparfall.
{ // Við erum að leita að laufinu [x, x] og erum í [i, j].
	if (i == j) p[e] += y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) urec(i, m, x, y, LEFT(e));
		else urec(m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}
void update(int x, int y) { return urec(0, n - 1, x, y, 1); }
int main()
{
	int i, x, y, z, n, q;
	scanf("%d%d", &n, &q);
	for (i = 0; i < 5*n; i++) p[i] = 0;
	while (q-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		x == 1 ? update(y, z) : printf("%d\n", query(y, z));
	}
	return 0;
}
