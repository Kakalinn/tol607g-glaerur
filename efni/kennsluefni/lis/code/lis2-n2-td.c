#include <stdio.h>
#include <string.h>
#define INF (1 << 30)
#define MAXN 1001
int min(int a, int b) { return a > b ? b : a; }

int v[MAXN], d[MAXN][MAXN];
int dp_lookup(int x, int y)                                                     // Finnur minnsta aftasta stak vaxandi hlutruna a[0:x] af lengd y.
{
    if (x == -1) return y == 0 ? -INF : INF;                                    // Grunntilfelli.
    if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því.
    if (v[x] < dp_lookup(x - 1, y - 1)) return d[x][y] = dp_lookup(x - 1, y);   // Við getum ekki bætt v[x] aftan á hlutrunu af lengd y - 1.
    return d[x][y] = min(dp_lookup(x - 1, y), v[x]);                            // Við getum bætt v[x] aftan á hlutrunu af lengd y - 1.
}

int lis(int *a, int n)                                                          // Finnur lengd lengstu vaxandi hlutruna a.
{
    int i, j, x;
    for (i = 0; i < n; i++) v[i] = a[i];
    for (i = 0; i < n; i++) for (j = 0; j < n + 1; j++) d[i][j] = -1;           // Upphafstillum minnistöfluna.
    for (x = n; dp_lookup(n - 1, x) == INF; x--);                               // Finnum lengdina á lengstu vaxandi hlutrununum.
    return x;
}

int main()
{
    int n, m, i, j, x;
    scanf("%d", &n);                                                            // Innlestur hafinn.
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    printf("%d\n", lis(a, n));                                                  // Reiknum og prentum svarið.
    return 0;
}
