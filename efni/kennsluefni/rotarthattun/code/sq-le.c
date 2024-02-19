// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
void prop(int *a, int x)                                                        // Framkvæmir þær uppfærslur sem á eftir að gera á hólf x.
{
    for (int i = 0; i < a[1]; i++) a[3 + x*a[1] + i] += a[a[2] + x];
    a[3 + a[0] + x] += a[a[2] + x]*a[1], a[a[2] + x] = 0;
}

int query(int *a, int x, int y)                                                 // Finnum summuna yfir [x, y - 1].
{
    prop(a, x/a[1]), prop(a, (y - 1)/a[1]);                                     // Pössum að ekki sé lygn uppfærsla í endahólfunum.
    int r = 0;
    while (x%a[1] != 0 && x < y) r += a[3 + x++];                               // Reiknum summuna frá x út að y eða enda hólfsins sem x tilheyrir.
    if (x == y) return r;                                                       // Við fórum ekki út í enda hólfsins svo við erum komin með svarið.
    while (y%a[1] != 0) r += a[3 + --y];                                        // Reiknum summuna frá y að upphafi hólfsins sem y tilheyrir.
    while (x < y) r += a[3 + a[0] + x/a[1]] + a[a[2] + x/a[1]]*a[1], x += a[1]; // Reiknum summuna í öllum hólfunum á milli hólfanna sem x og y tilheyra.
    return r;                                                                   // Skilum svarinu.
}

void update(int *a, int x, int y, int z)                                        // Bætum z við stökin [x, y - 1].
{
    prop(a, x/a[1]), prop(a, (y - 1)/a[1]);                                     // Pössum að ekki sé lygn uppfærsla í endahólfunum.
    while (x%a[1] != 0 && x < y) a[3 + x] += z, a[3 + a[0] + x++/a[1]] += z;    // Bætum z við öll stökin frá x að y eða enda hólfsins sem x tilheyrir.
    if (x == y) return;                                                         // Við fórum ekki út í enda hólfsins svo við erum komin með svarið.
    while (y%a[1] != 0) a[3 + --y] += z, a[3 + a[0] + y/a[1]] += z;             // Bætum z við öll stökin frá y að upphafi hólfins sem y tilheyrir.
    while (x < y) a[a[2] + x/a[1]] += z, x += a[1];                             // Bætum lygnum uppfærslum á öll hólfin á milli hólfanna sem x og y
}                                                                               //   tilheyra.

void init(int *a, int n)                                                        // Upphafstillir fyrir n og skilar stærð hólfanna. Fylkið a þarf að rúma
{                                                                               //   3 + 2*n stök.
    for (a[0] = n, a[1] = 0; a[1]*a[1] < a[0]; a[1]++);
    for (int i = 3; i < 2*a[0]; i++) a[i] = 0;
    a[2] = (a[0] + a[1] - 1)/a[1] + a[0] + 3;
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
    int n = 200;
    int a[3 + 2*n], b[n];
    for (i = 0; i < n; i++) b[i] = 0;
    init(a, n);
    while (q-- != 0)
    {
        x = rand()%(n - 1), w = x + 1 + rand()%(n - x - 1), y = rand()%(n*10);
        update(a, x, w, y);
        for (i = x; i < w; i++) b[i] += y;
        for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) assert(query(a, i, j) == slow(b, i, j));
    }
    return 0;
}
