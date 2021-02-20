// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 2000000
int a[MAXN], s[MAXN], o[MAXN], n, e; // n = e*e

void prop(int x) // Hjálparfall
{ // Framkvæmir þær uppfærslur sem á eftir að gera á fötu x.
	int i;
	s[x] += o[x]*e;
	for (i = 0; i < e; i++) a[x*e + i] += o[x];
	o[x] = 0;
}

int query(int x, int y)
{ // Finnum summuna yfir [x, y - 1].
	prop(x/e), prop((y - 1)/e);
    int r = 0;
	while (x%e != 0 && x < y) r += a[x++];
	if (x == y) return r;
	while (y%e != 0) r += a[--y];
	while (x < y) r += s[x/e] + o[x/e]*e, x += e;
    return r;
}

void update(int x, int y, int z)
{ // Bætum z við stökin [x, y - 1].
	prop(x/e), prop((y - 1)/e);
	while (x%e != 0 && x < y) a[x] += z, s[x++/e] += z;
	if (x == y) return;
	while (y%e != 0) a[--y] += z, s[y/e] += z;
	while (x < y) o[x/e] += z, x += e;
}

int slow(int* b, int l, int r)
{ // Línuleg útfærsla til að bera saman.
	int x = 0;
	while (l < r) x += b[l++];
	return x;
}

// Þetta forrit prófar range-sum-query, range-addition-update á slembnar uppfærlsur.
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
		update(x, w, y);
		for (i = x; i < w; i++) b[i] += y;
		for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) assert(query(i, j) == slow(b, i, j));
	}
	return 0;
}
