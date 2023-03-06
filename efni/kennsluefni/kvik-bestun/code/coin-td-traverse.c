#include <stdio.h>
#define MAXN 10001
#define MAXM 10001
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }
int n, m, a[MAXM], d[MAXN];
int dp_lookup(int x)                                                            // Minnsta klink sem þarf til að gefa til baka x.
{
    int i;
    if (x < 0) return INF;                                                      // Við gáfum of mikið klink til baka. Þessi lína þarf að vera fremst!
    if (d[x] != -1) return d[x];                                                // Við er búin að reikna svarið. Skilum því.
    if (x == 0) return 0;                                                       // Grunntilfelli.
    d[x] = INF;
    for (i = 0; i < m; i++) d[x] = min(d[x], dp_lookup(x - a[i]) + 1);          // Prófum að gefa allt klink til baka.
    return d[x];                                                                // Skilum því besta sem við fundum.
}

int dp_traverse(int n, int *r)
{
    int i = 0, mn, mni, j;
    while (n > 0)                                                               // Þessi lykkja keyrir þangað til við erum búin að gefa til baka.
    {
        for (mn = INF, j = 0; j < m; j++) if (mn > dp_lookup(n - a[j]) + 1)     // Ítrum í gegnum kliknið of finnum best sem við getum gefið til baka.
            mn = dp_lookup(n - a[j]) + 1, mni = j;
        r[i++] = a[mni];                                                        // Uppfærum svarið.
        n -= a[mni];
    }
    return i;
}

int main()                                                                      // Skiptimyntadæmið með endurtekningu.
{
    int i, r[MAXN];
    scanf("%d%d", &n, &m);                                                      // Innlestur hefts.
    for (i = 0; i < m; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    for (i = 0; i < n + 1; i++) d[i] = -1;                                      // Upphafstillum minnistöfluna.
    printf("%d\n", dp_lookup(n));                                               // Reiknum og prentum besta svarið.
    int k = dp_traverse(n, r);                                                  // Reiknum besta svarið ásamt besta klinkinu.
    printf("%d\n", k);                                                          // Prentum besta svarið.
    for (i = 0; i < k; i++) printf("%d ", r[i]);                                // Prentum besta klinkið.
    printf("\n");
    return 0;
}
