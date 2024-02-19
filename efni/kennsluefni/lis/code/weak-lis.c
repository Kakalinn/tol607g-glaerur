#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define INF (1LL << 62)
#define MAXN 1001
typedef long long ll;
ll max(ll a, ll b) { return a < b ? b : a; }

ll lis(ll *a, ll *b, ll n)                                                      // Finnur eina af lengstu vaxandi hlutrunum a.
{
    ll i, j, x, y, d[n + 1], v[n], e[n];
    for (i = 0; i < n; i++) v[i] = (a[i] << 32) + i;
    for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;                     // Upphafstillum minnistöfluna.
    for (i = 0; i < n; i++)
    {
        ll r = -1, s;                                                           // Reiknum, með helmingunarleit, hvar við setjum v[i] í minnistöfluna.
        for (s = n + 1; s >= 1; s /= 2)
            while (r + s < n + 1 && d[r + s] < v[i]) r += s;                    // ATH: Eftir leitina er vísirinn r - 1!
        d[r + 1] = v[i], e[i] = d[r];                                           // Setjum v[i] í minnistöflun og geymum hvað stak kom á undan.
    }
    for (x = n; d[x] == INF; x--);                                              // Finnum lengdina á lengstu hlutrununum.
    for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (v[i] == y)            // Finnum eina af lengstu hlutrununum.
        y = e[i], b[j--] = v[i] >> 32;
    return x;                                                                   // Skilum lengdinni á hlutrununni sem við fundum.
}



// Allt hér að neðan, að main(...) utanskyldu, er til að sannreyna 
//    að fallið fyrir ofan sé rétt.

ll v[MAXN], d[MAXN];
ll dp_lookup(ll x)
{
    if (d[x] != -1) return d[x];
    if (x == 0) return 1;
    ll i;
    for (d[x] = 1, i = 0; i < x; i++) if (v[i] <= v[x])
        d[x] = max(d[x], dp_lookup(i) + 1);
    return d[x];
}

ll dp_lis(ll *a, ll n)                                                          // Reiknar svarið með kvikri bestun í O(n^2) til að bera saman.
{
    ll i, r = 1;
    for (i = 0; i < n; i++) d[i] = -1, v[i] = a[i];
    for (i = 0; i < n; i++) r = max(r, dp_lookup(i));
    return r;
}

void shuffle(ll *a, ll m, ll n)                                                 // Stokkar m af stökum í a og setur fremst.
{
    ll i, j, s;
    for (i = 0; i < m; i++)
    {
        j = i + rand()%(n - i);
        s = a[j]; a[j] = a[i]; a[i] = s;
    }
}

ll issubseq(ll* a, ll n, ll* b, ll m)                                           // Er b hlutruna í a?
{
    if (n < m) return 0;
    ll i, j = 0;
    for (i = 0; i < n; i++) if (j < m && a[i] == b[j]) j++;
    return j == m;
}

ll isinc(ll* a, ll n)                                                           // Er a vaxandi?
{
    ll i;
    for (i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) break;
    return i == n - 1;
}

void check_random(ll n)                                                         // Ber saman tvær útfærslur á LIS.
{
    ll i, a[n], b[n], x, y;
    for (i = 0; i < n; i++) a[i] = (i/2)*4;
    shuffle(a, n, n);
    x = dp_lis(a, n), y = lis(a, b, n);
    if (x != y)
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%lld ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%lld ", b[i]); printf("\n");
        printf("The sequence found was too short (%d < %d).\n", y, x);
        assert(0);
    }
    if (!issubseq(a, n, b, y))
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%lld ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%lld ", b[i]); printf("\n");
        printf("The sequence found was not a subsequence.\n");
        assert(0);
    }
    if (!isinc(b, y))
    {
        printf("seq: "); for (i = 0; i < n; i++) printf("%lld ", a[i]); printf("\n");
        printf("ans: "); for (i = 0; i < y; i++) printf("%lld ", b[i]); printf("\n");
        printf("The sequence found was not increasing.\n");
        assert(0);
    }
}

int main()
{
    srand(time(NULL));
    ll q = 1000000, n, m, i, j, x, l;
#if 0                                                                           // 1 og 0 skipta milli tilvika.
    printf("Skrifið inntak\n");
    scanf("%d", &n);                                                            // Innlestur hafinn.
    ll a[n], b[n];
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
