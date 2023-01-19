#include <stdio.h>
#include <stdlib.h>
#define rep(E, F) for (E = 0; E < (F); E++)
typedef struct {int x, y;} ii;

int cmpx(const void* p1, const void* p2) {return ((ii*)p1)->x - ((ii*)p2)->x;}
int cmpy(const void* p1, const void* p2) {return ((ii*)p1)->y - ((ii*)p2)->y;}

void compress(int* a, int n)
{
	int i, j, x, k;
	ii b[n];
	rep(i, n) b[i].x = a[i], b[i].y = i;
	qsort(b, n, sizeof(b[0]), cmpx);
	for (i = k = 0; i < n; i = j, k++)
		for (j = i, x = b[i].x; j < n && b[j].x == x; j++)
			b[j].x = k;
	qsort(b, n, sizeof(b[0]), cmpy);
	rep(i, n) a[i] = b[i].x;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	compress(a, n);
	rep(i, n) printf("%d ", a[i]);
	printf("\n");
}
