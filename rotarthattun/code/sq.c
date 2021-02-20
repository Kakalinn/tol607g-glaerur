// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 2000000
int a[MAXN], s[MAXN], n, e; // n = e*e

void update(int x, int y)
{ // Bætir y við x-ta stakið.
	s[x/e] += y;
	a[x] += y;
}

int query(int x, int y)
{ // Finnum summuna yfir [x, y - 1].
    int r = 0;
	while (x%e != 0 && x < y) r += a[x++];
	if (x == y) return r;
	while (y%e != 0) r += a[--y];
	while (x < y) r += s[x/e], x += e;
    return r;
}

int slow(int* b, int l, int r)
{ // Línulegt fall til að bera saman við.
	int x = 0;
	while (l < r) x += b[l++];
	return x;
}

// Þetta forrit prófar range-sum-query, point-addition-update á slembnar uppfærlsur.
// Eftir hverja uppfærslu eru allar mögulegar fyrirspurnir framkvæmdar.
// Svo forritið er hægt, nánar O(q*n^3).
// Það er allt í lagi að hafa q stórt.
// Forritið þarf ekki að klára keyrlsuna á meðan n er nógu lítið (helst minna en 100).
// Gefna talan n er stækkuð þangað til að hún er ferningstala.
int main()
{
	srand(time(NULL));
	int i, j, q = 1000000, x, w, y;
	e = 1, n = 100;
	while (e*e < n) e++;
	n = e*e;
	int b[n];
	for (i = 0; i < n; i++) b[i] = a[i] = 0;
	for (i = 0; i < e; i++) s[i] = 0;
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + 1 + rand()%(n - x - 1), y = rand()%(n*10);
		update(x, y);
		b[x] += y;
		for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) assert(query(i, j) == slow(b, i, j));
	}
	return 0;
}
