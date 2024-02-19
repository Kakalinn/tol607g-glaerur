#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

typedef struct { int v, or, ok; } node;
node p[5*MAXN];

void prop(int x, int y, int e)                                                  // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
{
    p[e].v += (y - x + 1)*p[e].or + p[e].ok*(y - x + 1)*(y - x)/2;              // Uppfærum gildið í hnútnum, sjá glærur.
    if (x != y)
        p[RIGHT(e)].or += p[e].or + ((y - x)/2 + 1)*p[e].ok,                    // Skiptum uppfærslunni í tvennt, sjá glærur.
            p[LEFT(e)].or += p[e].or, p[LEFT(e)].ok += p[e].ok,
            p[RIGHT(e)].ok += p[e].ok;
    p[e].or = p[e].ok = 0;
}

int qrec(int i, int j, int x, int y, int e)                                     // Við erum að leita að bili [x, y] og erum í [i, j].
{
    prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
    if (x == i && y == j) return p[e].v;                                        // Við fundum akkúrat bilið.
    int m = (i + j)/2;                                                          // Finnum miðju bilsins sem við erum að leita í.
    if (y <= m) return qrec(i, m, x, y, LEFT(e));                               // Bilið sem við erum að leita að er vinstra megin við miðjuna.
    else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));                      // Bilið sem við erum að leita að er hægra megin við miðjuna.
    return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));      // Miðjan skiptir bilinu í tvennt.
}
int query(int x, int y)                                                         // Finnum summuna yfir [x, y].
{
    return qrec(0, p[0].v - 1, x, y, 1);
}

void urec(int i, int j, int x, int y, int zr, int e)                            // Við erum að leita að bili [x, y] og erum í [i, j].
{
    prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
    if (x == i && y == j) { p[e].or = zr; p[e].ok = 1; return; }                // Við fundum akkúrat bilið.
    int m = (i + j)/2;                                                          // Finnum miðju bilsins sem við erum að leita í.
    p[e].v += (y - x + 1)*zr + (y - x + 1)*(y - x)/2;                           // Uppfærum gildið sem tréð geymir.
    if (y <= m) urec(i, m, x, y, zr, LEFT(e));                                  // Bilið sem við erum að leita að er vinstra megin við miðjuna.
    else if (x > m) urec(m + 1, j, x, y, zr, RIGHT(e));                         // Bilið sem við erum að leita að er hægra megin við miðjuna.
    else urec(i, m, x, m, zr, LEFT(e)),
        urec(m + 1, j, m + 1, y, zr + (m - x + 1), RIGHT(e));                   // Miðjan skiptir bilinu í tvennt.
}
void update(int x, int y)                                                       // Bætum 0 við stak x, 1 við stak x + 1, ..., y - x - 1 við stak y.
{
    urec(0, p[0].v - 1, x, y, 0, 1);
}

void init(int n)                                                                // Upphafstillum tréð. Fylkin o og p þurfa að rúma 5*n stök!
{
    for (int i = 0; i < 5*n; i++) p[i].v = p[i].or = p[i].ok = 0;
    p[0].v = n;                                                                 // Til þæginda geymum við stærðina í stakinu sem er ekki notað í trénu.
}

int slow(int* a, int l, int r)
{
    int x = 0;
    while (l <= r) x += a[l++];
    return x;
}

int main()
{
    srand(time(NULL));
    int i, j, k, x, z, w, n = 400, q = 400;
    int a[n];
    for (i = 0; i < n; i++) a[i] = 0;
    init(n);
    while (q-- != 0)
    {
        x = rand()%(n - 1), w = x + rand()%(n - x);
        update(x, w);
        for (i = x, k = 0; i <= w; i++, k++) a[i] += k;
        for (i = 0; i < n; i++) for (j = i; j < n; j++) assert(query(i, j) == slow(a, i, j));
    }
    return 0;
}
