#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define INF (1 << 30)
int max(int a, int b) { return a < b ? b : a; }

int lis(int *a, int *b, int n)                                                  // Finnur eina af lengstu vaxandi hlutrunum a.
{
    int i, j, x, y, r, s, d[n + 1], e[n];
    for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;                     // Upphafstillum minnistöfluna.
    for (i = 0; i < n; i++)
    {
        for (r = -1, s = n + 1; s >= 1; s /= 2)                                 // Reiknum, með helmingunarleit, hvar við setjum a[i] í minnistöfluna.
            while (r + s < n + 1 && d[r + s] < a[i]) r += s;                    // ATH: Eftir leitina er vísirinn r - 1!
        d[r + 1] = a[i], e[i] = d[r];                                           // Setjum a[i] í minnistöflun og geymum hvað stak kom á undan.
    }
    for (x = n; d[x] == INF; x--);                                              // Finnum lengdina á lengstu hlutrununum.
    for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (a[i] == y)            // Finnum eina af lengstu hlutrununum.
        y = e[i], b[j--] = a[i];
    return x;                                                                   // Skilum lengdinni á hlutrununni sem við fundum.
}








// Allt hér að neðan, að main(...) utanskyldu, er til að sannreyna 
//    að fallið fyrir ofan sé rétt.

#define MAXN 1001
int v[MAXN], d[MAXN];
int dp_lookup(int x)
{
    if (d[x] != -1) return d[x];
    if (x == 0) return 1;
    int i;
    for (d[x] = 1, i = 0; i < x; i++) if (v[i] < v[x])
        d[x] = max(d[x], dp_lookup(i) + 1);
    return d[x];
}

int dp_lis(int *a, int n)                                                       // Reiknar svarið með kvikri bestun í O(n^2) til að bera saman.
{
    int i, r = 1;
    for (i = 0; i < n; i++) d[i] = -1, v[i] = a[i];
    for (i = 0; i < n; i++) r = max(r, dp_lookup(i));
    return r;
}

void shuffle(int *a, int m, int n)                                              // Stokkar m af stökum í a og setur fremst.
{
    int i, j, s;
    for (i = 0; i < m; i++)
    {
        j = i + rand()%(n - i);
        s = a[j]; a[j] = a[i]; a[i] = s;
    }
}

int issubseq(int* a, int n, int* b, int m)                                      // Er b hlutruna í a?
{
    if (n < m) return 0;
    int i, j = 0;
    for (i = 0; i < n; i++) if (j < m && a[i] == b[j]) j++;
    return j == m;
}

int isinc(int* a, int n)                                                        // Er a vaxandi?
{
    int i;
    for (i = 0; i < n - 1; i++) if (a[i] >= a[i + 1]) break;
    return i == n - 1;
}

void check_random(int n)                                                        // Ber saman tvær útfærslur á LIS.
{
    int i, a[n], b[n], x, y;
    for (i = 0; i < n; i++) a[i] = (i/2)*4;
    shuffle(a, n, n);
    x = dp_lis(a, n), y = lis(a, b, n);
    if (x != y)
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%d ", b[i]); printf("\n");
        printf("The sequence found was too short (%d < %d).\n", y, x);
        assert(0);
    }
    if (!issubseq(a, n, b, y))
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%d ", b[i]); printf("\n");
        printf("The sequence found was not a subsequence.\n");
        assert(0);
    }
    if (!isinc(b, y))
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%d ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%d ", b[i]); printf("\n");
        printf("The sequence found was not increasing.\n");
        assert(0);
    }
}

int main()
{
    srand(time(NULL));
    int q = 1000000, n, m, i, j, x, l;
#if 0                                                                           // 1 og 0 skipta milli tilvika.
    scanf("%d", &n);                                                            // Innlestur hafinn.
    int a[n], b[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    l = lis(a, b, n);                                                           // Reiknum svarið.

    printf("Lend lengstu vaxandi hlutruna er %d\n", l);                         // Prentum svarið.
    for (i = 0; i < l; i++) printf("%d ", b[i]);
    printf("\n");
#else
    while (q--) check_random(1000);                                             // Berum útfærsluna saman við slembið inntak af lengd 1000, q sinnum.
#endif
    return 0;
}
