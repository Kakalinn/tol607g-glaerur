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
int query(int x, int y)
{ // Finnum summuna yfir [x, y].
	return qrec(0, n - 1, x, y, 1);
}

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
void update(int x, int y)
{ // Bætum y við x-ta stakið.
	return urec(0, n - 1, x, y, 1);
}

int slow(int* a, int x, int y)
{ // Línuleg útfærsla til að bera saman.
	int r = 0;
	while (x <= y) r += a[x++];
	return r;
}

// Þetta forrit prófar range-sum-query, point-addition-update á slembnar uppfærlsur.
// Eftir hverja uppfærslu eru allar mögulegar fyrirspurnir framkvæmdar.
// Svo forritið er hægt, nánar O(q*n^3).
// Það er allt í lagi að hafa q stórt.
// Forritið þarf ekki að klára keyrlsuna á meðan n er nógu lítið (helst minna en 400).
int main()
{
	srand(time(NULL));
	n = 400;
	int i, j, x, y, z, q = 400, m = 100;
	int a[n];
	for (i = 0; i < n; i++) a[i] = 0;
	for (i = 0; i < 5*n; i++) p[i] = 0;
	while (q-- != 0)
	{
		x = rand()%n, y = x + rand()%(n - x), z = rand()%(2*m + 1) - m;
		update(x, z), a[x] += z;
		for (i = 0; i < n; i++) for (j = i; j < n; j++) assert(query(i, j) == slow(a, i, j));
	}
	return 0;
}
