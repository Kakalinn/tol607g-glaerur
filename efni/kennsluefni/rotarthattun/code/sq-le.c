// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
int a[MAXN], s[MAXN], o[MAXN], n, e;                                            // Við þurfum að n = e*e gildi.

void prop(int x)                                                                // Framkvæmir þær uppfærslur sem á eftir að gera á hólf x.
{
	int i;
	s[x] += o[x]*e;
	for (i = 0; i < e; i++) a[x*e + i] += o[x];
	o[x] = 0;
}

int query(int x, int y)                                                         // Finnum summuna yfir [x, y - 1].
{
	prop(x/e), prop((y - 1)/e);                                                 // Pössum að ekki sé lygn uppfærsla í endahólfunum.
    int r = 0;
	while (x%e != 0 && x < y) r += a[x++];                                      // Reiknum summuna frá x út að y eða enda hólfsins sem x tilheyrir.
	if (x == y) return r;                                                       // Við fórum ekki út í enda hólfsins svo við erum komin með svarið.
	while (y%e != 0) r += a[--y];                                               // Reiknum summuna frá y að upphafi hólfsins sem y tilheyrir.
	while (x < y) r += s[x/e] + o[x/e]*e, x += e;                               // Reiknum summuna í öllum hólfunum á milli hólfanna sem x og y tilheyra.
    return r;                                                                   // Skilum svarinu.
}

void update(int x, int y, int z)                                                // Bætum z við stökin [x, y - 1].
{
	prop(x/e), prop((y - 1)/e);                                                 // Pössum að ekki sé lygn uppfærsla í endahólfunum.
	while (x%e != 0 && x < y) a[x] += z, s[x++/e] += z;                         // Bætum z við öll stökin frá x að y eða enda hólfsins sem x tilheyrir.
	if (x == y) return;                                                         // Við fórum ekki út í enda hólfsins svo við erum komin með svarið.
	while (y%e != 0) a[--y] += z, s[y/e] += z;                                  // Bætum z við öll stökin frá y að upphafi hólfins sem y tilheyrir.
	while (x < y) o[x/e] += z, x += e;                                          // Bætum lygnum uppfærslum á öll hólfin á milli hólfanna sem x og y
}                                                                               //   tilheyra.

int init(int n)                                                                 // Upphafstillir fyrir n og skilar stærð hólfanna.
{
	int i, r = 0;
	while (r*r < n) r++;
	for (i = 0; i < r; i++) o[i] = s[i] = 0;
	return r;
}

int slow(int* b, int l, int r)                                                  // Línuleg útfærsla til að bera saman.
{
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
	n = 200;
	int b[n];
	for (i = 0; i < n; i++) b[i] = a[i] = 0;
	e = init(n);
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + 1 + rand()%(n - x - 1), y = rand()%(n*10);
		update(x, w, y);
		for (i = x; i < w; i++) b[i] += y;
		for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) assert(query(i, j) == slow(b, i, j));
	}
	return 0;
}
