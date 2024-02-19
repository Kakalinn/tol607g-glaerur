#include <stdio.h>
#include <string.h>
#define INF (1 << 30)
#define MAXN 1001
int min(int a, int b) { return a > b ? b : a; }

int lis(int *a, int *b, int n)                                                  // Finnur eina af lengstu vaxandi hlutrunum a.
{
    int i, j, x, y, d[n + 1][n + 1];
    for (i = 0; i < n + 1; i++) d[0][i] = INF;                                  // Grunntilfelli.
    for (i = 0; i < n + 1; i++) d[i][0] = -INF;                                 // Grunntilfelli.
    for (i = 1; i < n + 1; i++) for (j = 0; j < n + 1; j++)
    {
        if (a[i - 1] < d[i - 1][j - 1]) d[i][j] = d[i - 1][j];                  // Við getum ekki bætt a[i - 1] aftan á hlutrunu af lengd j - 1.
        else d[i][j] = min(d[i - 1][j], a[i - 1]);                              // Við getum bætt a[i - 1] aftan á hlutrunu af lengd j - 1.
    }
    for (x = n; d[n][x] == INF; x--);                                           // Finnum lengdina á lengstu vaxandi hlutrununum.
    for (i = 0; i < x; i++) b[i] = d[n - x + i + 1][i + 1];                     // Lesum eina af lengstu vaxandi hlutrununum úr minnistöflunni.
    return x;                                                                   // Skilum lengdinni.
}

int main()
{
    int n, m, i, j, x, l;
    scanf("%d", &n);                                                            // Innlestur hafinn.
    int a[n], b[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    l = lis(a, b, n);                                                           // Reinkum eina af lengstu vaxandi hlutrununum.

    printf("Lengd lengstu vaxandi hlutrunanna er %d\n", l);                     // Prentum svarið.
    for (i = 0; i < l; i++) printf("%d ", b[i]);
    printf("\n");

    return 0;
}
