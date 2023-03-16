#include <stdio.h>
#define MAXN 10001
#define MAXM 10001
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int n, m, a[MAXM];
int d[MAXN][MAXM];
int dp_lookup(int x, int y)                                                     // Minnsta klink til að gefa x til baka með klinki y, y + 1, ..., n.
{
    if (x < 0) return INF;                                                      // Við reyndum að gefa of mikið til baka. Það má ekki.
    if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því sem við reiknuðum þá.
    if (y == m) return x == 0 ? 0 : INF;                                        // Ekkert klink eftir. Þá þarf x að vera núll til að þetta sé löglegt.
    return d[x][y] = min(dp_lookup(x, y + 1),                                   // Annars skilum við betra af: nota ekki y-ta klinkið vs.
            dp_lookup(x - a[y], y + 1) + 1);                                    //   nota y-ta klinkið.
}

int main()                                                                      // Skiptimyntadæmið án endurtekningar.
{
    int i, j;
    scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
    for (i = 0; i < m; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;       // Upphafstillum minnistöfluna.
    printf("%d\n", dp_lookup(n, 0));                                            // Prentum svarið.
    for (i = 0; i < n + 1; i++)
        printf("%3d ", dp_lookup(i, 0) == INF ? -1 : dp_lookup(i, 0));          // Prentum svarið fyrir allar tölur minni eða jafnar n.
    printf("\n");
    return 0;
}
