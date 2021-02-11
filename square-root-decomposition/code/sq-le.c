// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 2000000
int a[MAXN], s[MAXN], o[MAXN], n, e;
void update(int x, int y)
{
	s[x/e] = s[x/e] - a[x] + y;
	a[x] = y;
}

void prop(int x)
{
	int i;
	s[x] += o[x]*e;
	for (i = 0; i < e; i++) a[x*e + i] += o[x];
	o[x] = 0;
}

int query(int x, int y)
{ // [x, y[
	prop(x/e), prop((y - 1)/e);
    int r = 0;
	while (x%e != 0 && x < y) r += a[x++];
	if (x == y) return r;
	while (y%e != 0) r += a[--y];
	while (x < y) r += s[x/e] + o[x/e]*e, x += e;
    return r;
}

void rupdate(int x, int y, int z)
{ // [x, y[
	prop(x/e), prop((y - 1)/e);
	while (x%e != 0 && x < y) a[x] += z, s[x++/e] += z;
	if (x == y) return;
	while (y%e != 0) a[--y] += z, s[y/e] += z;
	while (x < y) o[x/e] += z, x += e;
}

int slow(int* b, int l, int r)
{
	int x = 0;
	while (l <= r) x += b[l++];
	return x;
}

int main()
{
	srand(time(NULL));
	int i, q = 1000000, x, w, y, z;
	e = 1, n = 10000;
	while (e*e < n) e++;
	n = e*e;
	int b[n];
	for (i = 0; i < n; i++) b[i] = a[i] = 0;
	for (i = 0; i < e; i++) s[i] = 0;
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + 1 + rand()%(n - x - 1), y = rand()%(n*10), z = rand()%2;
		//if (z) a[x] = y, update(x, a[x]);
		if (z)
		{
			//printf("updating [%d, %d[ by %d\n", x, w, y);
			rupdate(x, w, y);
			for (i = x; i < w; i++) b[i] += y;
		}
		else if (query(x, w + 1) != slow(b, x, w)) break;
		//printf("now we have that:\n");
		//printf("b: "); for (i = 0; i < n; i++) printf("%4d ", b[i]); printf("\n");
		//printf("a: "); for (i = 0; i < n; i++) printf("%4d ", query(i, i + 1)); printf("\n");
		//printf("s: "); for (i = 0; i < e; i++) printf("%4d ", s[i]); printf("\n");
		//printf("o: "); for (i = 0; i < e; i++) printf("%4d ", o[i]); printf("\n");
	}
	if (q != -1)
	{
		// this is if it fails
		printf("[%d %d], %d %d\n", x, w + 1, query(x, w + 1), slow(b, x, w));
		for (i = 0; i < n; i++) printf("%4d ", query(i, i + 1)); printf("\n");
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
