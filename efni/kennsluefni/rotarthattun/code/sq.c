// ATH: Bilið í query er núna hálfopið.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
void update(int *a, int x, int y)                                               // Bætir y við x-ta stakið.
{ 
    a[2 + a[0] + x/a[1]] += y, a[2 + x] += y;                                   // Uppfærum gildið og hólfið sem x tilheyrir.
}

int query(int *a, int x, int y)                                                 // Finnum summuna yfir [x, y - 1].
{
    int r = 0;
    while (x%a[1] != 0 && x < y) r += a[2 + x++];                               // Reiknum summun frá x út að y eða enda hólfsins sem x tilheyrir.
    if (x == y) return r;                                                       // Við fórum ekki út í enda hólfsins svo við erum komin með svarið.
    while (y%a[1] != 0) r += a[2 + --y];                                        // Reiknum summuna frá y að upphafi hólfsins sem y tilheyrir.
    while (x < y) r += a[2 + a[0] + x/a[1]], x += a[1];                         // Reiknum summuna í öllum hólfinum á milli hólfanna sem x og y yilheyra.
    return r;                                                                   // Skilum svarinu.
}

void init(int *a, int n)                                                        // Upphafstillir fyrir n og skilar stærð hólfanna. Fylkið a þarf að rúma
{                                                                               //   3 + 2*n stök.
    for (a[0] = n, a[1] = 0; a[1]*a[1] < a[0]; a[1]++);
    for (int i = 2; i < 2*n; i++) a[i] = 0;
}

int slow(int* b, int l, int r)                                                  // Línulegt fall til að bera saman við.
{
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
    int i, j, q = 1000000, x, y;
    int n = 200;
    int a[3 + 2*n], b[n];
    for (i = 0; i < n; i++) b[i] = 0;
    init(a, n);
    while (q-- != 0)
    {
        x = rand()%(n - 1), y = rand()%(n*10);
        update(a, x, y);
        b[x] += y;
        for (i = 0; i < n; i++) for (j = i + 1; j <= n; j++) assert(query(a, i, j) == slow(b, i, j));
    }
    return 0;
}
