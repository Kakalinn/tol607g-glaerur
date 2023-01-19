#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 2000001
typedef struct { int x, y, z; } ii;

int cmp(const void* p1, const void* p2) { return ((ii*)p1)->z - ((ii*)p2)->z; }

int p[MAXN]; // = [-1, -1, ..., -1]
int find(int x)
{
	return p[x] < 0 ? x : (p[x] = find(p[x]));
}
void join(int x, int y)
{
	int rx = find(x), ry = find(y);
	if (rx == ry) return;
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
	else p[rx] += p[ry], p[ry] = rx;
}

int kruskal(ii* e, ii* mst, int m)
{
	int i, j = 0, r = 0;
	rep(i, MAXN) p[i] = -1;
	qsort(e, m, sizeof(e[0]), cmp);
	rep(i, m) if (find(e[i].x) != find(e[i].y))
	{
		r += e[i].z;
		join(e[i].x, e[i].y);
		mst[j++] = e[i];
	}
	return r;
}

int main()
{
	int n, m, x, y, z, i;
	scanf("%d%d", &n, &m);
	ii a[m], mst[n - 1];
	rep(i, m) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	rep(i, m) a[i].x--, a[i].y--;
	printf("Staerdin a minnsta spannandi trenu er %d.\n", kruskal(a, mst, m));
	printf("Eftirfarandi leggir eru i minnsta spannandi tre netsins:\n");
	rep(i, n - 1) printf("  (%d, %d)\n", mst[i].x, mst[i].y);
	return 0;
}
