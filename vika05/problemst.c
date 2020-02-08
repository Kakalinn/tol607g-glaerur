#include <stdio.h>
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int max(int a, int b) { return a > b ? a : b; }
int queryl(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (max(queryl(p, i, m, x, LEFT(e)), p[RIGHT(e)])) : (queryl(p, m + 1, j, x, RIGHT(e)));
}

int queryr(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryr(p, i, m, x, LEFT(e))) : (max(p[LEFT(e)], queryr(p, m + 1, j, x, RIGHT(e))));
}

int query(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query(p, i, m, x, y, LEFT(e));
	if (x > m && y > m) return query(p, m + 1, j, x, y, RIGHT(e));
	return max(queryl(p, i, m, x, LEFT(e)), queryr(p, m + 1, j, y, RIGHT(e)));
}

void update(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) update(p, i, m, x, y, LEFT(e));
		else update(p, m + 1, j, x, y, RIGHT(e));
		p[e] = max(p[LEFT(e)], p[RIGHT(e)]);
	}
}

int main()
{
	int n, m, i, x, y, z;
	scanf("%d%d", &n, &m);
	int a[n], p[4*n + 1];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));
	for (i = 0; i < 4*n + 1; i++) p[i] = 0;
	for (i = 0; i < n; i++) update(p, 0, n - 1, i, a[i], 1);
	while (m-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) update(p, 0, n - 1, y - 1, z, 1);
		if (x == 2) printf("%d\n", query(p, 0, n - 1, y - 1, z - 1, 1));
	}

	return 0;
}
