#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)

int query(int *p, int x, int y)
{ // Finnum summuna yfir [x, y].
    int i1 = 0, i2 = 0, j1 = p[0] - 1, j2 = p[0] - 1, e1 = 1, e2 = 1, r = 0;
    while (i1 != j1 && i2 != j2)
    {
        int m1 = (i1 + j1)/2, m2 = (i2 + j2)/2;
        (x <= m1) ? (j1 = m1, e1 = LEFT(e1)) : (i1 = m1 + 1, e1 = RIGHT(e1));
        (y <= m2) ? (j2 = m2, e2 = LEFT(e2)) : (i2 = m2 + 1, e2 = RIGHT(e2));
    }
    if (e1 == e2) return p[e1];
    r += i1 == j1 || x == i1 ? p[e1] : p[RIGHT(e1)];
    r += i2 == j2 || y == j2 ? p[e2] : p[LEFT(e2)];
    for (; e1/2 != e2/2; e1 /= 2, e2 /= 2)
        r += e1%2 ? 0 : p[e1 + 1], r += e2%2 ? p[e2 - 1] : 0;
    return r;
}

void update(int *p, int x, int y)
{ // Setjum x-ta stakið sem y.
    int i = 0, j = p[0] - 1, e = 1, m;
    for (m = (i + j)/2; i != j; m = (i + j)/2)
        (x <= m) ? (j = m, e = LEFT(e)) : (i = m + 1, e = RIGHT(e));
    p[e] = y, e /= 2;
    while (e > 0) p[e] = p[LEFT(e)] + p[RIGHT(e)], e /= 2;
}

void init(int *p, int n)
{
    int i;
    for (i = 0; i < 5*n; i++) p[i] = 0;
    p[0] = n;
}

int slow(int* a, int x, int y)
{ // Línuleg útfærsla til að bera saman.
    int r = 0;
    while (x <= y) r += a[x++];
    return r;
}

// Þetta forrit prófar range-sum-query, point-assignment-update á slembnar uppfærlsur.
// Eftir hverja uppfærslu eru allar mögulegar fyrirspurnir framkvæmdar.
// Svo forritið er hægt, nánar O(q*n^3).
// Það er allt í lagi að hafa q stórt.
// Forritið þarf ekki að klára keyrlsuna á meðan n er nógu lítið (helst minna en 400).
int main()
{
    srand(time(NULL));
    int i, j, x, y, z, n = 100, q = 10000, m = 100, p[n*5], a[n];
    for (i = 0; i < n; i++) a[i] = 0;
    init(p, n);
    while (q-- != 0)
    {
        x = rand()%n, y = x + rand()%(n - x), z = rand()%(2*m + 1) - m;
        update(p, x, z), a[x] = z;
        for (i = 0; i < n; i++) for (j = i; j < n; j++) if (query(p, i, j) != slow(a, i, j))
        {
            printf(">> failed %d %d | %d %d\n", i, j, query(p, i, j), slow(a, i, j));
            assert(0);
        }
    }
    return 0;
}
