#include <stdio.h>
#include <assert.h>
#define MAXN 2001
#define MAXC 2001
#define INF (1 << 30)
int max(int a, int b) { if (a > b) return a; return b; }

int d[MAXN][MAXC], a[MAXN], b[MAXN];
int dp_lookup(int x, int y)                                                     // Hæsta verðgildi sem má fá með pakpokastærð y og hluti 1, 2, ..., x.
{
    if (y < 0) return -INF;                                                     // Við erum búin að setja of mikið í pokann.
    if (x < 0) return 0;                                                        // Engir hlutir eftir.
    if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því.
    return d[x][y] = max(dp_lookup(x - 1, y),                                   // Annaðhvort veljum við x-ta hlutinn eða ekki, og skilum betra.
            dp_lookup(x - 1, y - b[x]) + a[x]);
}

void knapsack(int *v, int *w, int *r, int n, int c)                             // Leysir bakpokadæmið. Fylkið r segir hvaða hluti á að taka.
{
    int i, j;
    for (i = 0; i < n; i++) for (j = 0; j <= c; j++) d[i][j] = -1;              // Upphafstillum minnistöfluna.
    for (i = 0; i < n; i++) a[i] = v[i], b[i] = w[i], r[i] = 0;                 // Upphafstillum restina.
    for (j = c, i = n - 1; i >= 0; i--)                                         // Ítrum í gegnum alla hlutina.
        if (dp_lookup(i - 1, j) < dp_lookup(i - 1, j - w[i]) + v[i])            // Athugum hvort það sé betra að taka i-ta hlutinn en ekki.
            j -= w[i], r[i] = 1;                                                // Tökum hlutinn og uppfærum gildin.
}

int main()
{
    int k, n, c, i, j, v[MAXN], w[MAXN], r[MAXN];
    scanf("%d%d", &n, &c);                                                      // Innlestur hefst.
    for (i = 0; i < n; i++) scanf("%d%d", &v[i], &w[i]);                        // Innlestri lokið.
    knapsack(v, w, r, n, c);                                                    // Reiknum svarið.
    for (k = i = 0; i < n; i++) k += r[i];                                      // Teljum hvað við völdum marga hluti.
    printf("%d\n", k);                                                          // Prentum hvað við völdum marga hluti.
    for (i = 0; i < n; i++) if (r[i]) printf("%d ", i + 1);                     // Prentum hlutina sem við völdum.
    printf("\n");
    return 0;
}
