#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 100000
typedef long long ll;
typedef __int128 lll;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a%b);
}

ll bigprod(ll x, ll y, ll m)
{
    return ((lll)x*y)%m;
}

ll modpow(ll x, ll n, ll m)
{ 
    ll r = 1;
    while (n > 0) 
    { 
        if (n%2 == 1) r = bigprod(r, x, m);
        n = n/2;
        x = bigprod(x, x, m);
    } 
    return r; 
}

int miller_rabin(ll n)
{
    if (n%2 == 0) return n == 2;
    if (n <= 3) return n == 3;
    ll i, k, s = 0, d = n - 1, t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    while (d%2 == 0) d /= 2, s++;
    for (k = 0; k < 12; k++) if (t[k] <= n - 2)
    {
        ll a = t[k];
        ll x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        for (i = 0; i < s - 1; i++) if ((x = bigprod(x, x, n)) == n - 1) break;
        if (i == s - 1) return 0;
    }
    return 1;
}

ll rho(ll n)                                                                    // Þetta fall skilar þætti í n. Keyrslutíminn er slembinn.
{
    ll s[8] = {2, 3, 4, 5, 7, 11, 13, 1031}, i, j, a, x, y, d;
    for (a = 1;; a++) for (j = 0; j < 8; j++)
    {
        x = y = s[j], d = 1;
        while (d == 1)
        {
            x = (bigprod(x, x, n) + a)%n;
            y = (bigprod(y, y, n) + a)%n;
            y = (bigprod(y, y, n) + a)%n;
            d = gcd(llabs(x - y), n);
        }
        if (d != n) return d;
    }
}

ll e[MAXN], p[MAXN], pp = 0;
void eratos()
{
    ll i, j;
    for (i = 0; i < MAXN; i++) e[i] = 0;
    e[0] = e[1] = -1;
    for (i = 0; i < MAXN; i++) if (e[i] == 0)
        for (j = i; j < MAXN; j += i) if (e[j] == 0) e[j] = i;
    for (i = 0; i < MAXN; i++) if (e[i] == i) p[pp++] = i;
}

ll pollard_rho(ll n, ll *a)                                                     // Þetta fall frumþáttar n og geymir þættina í a. Fylkið a þarf að rúma
{                                                                               //  alla frumþætti n, sem eru aldrei fleiri en log(n).
    ll i, r, c = 0, s[200], p[6] = {2, 3, 5, 7, 11, 13};
    for (i = 0; i < 6; i++) while (n%p[i] == 0) n /= p[i], a[c++] = p[i];       // Styttum út með nokkrum harðkóðuðum frumtölum, því reikniritið er voða
    if (n == 1) return c;                                                       //   krúttlegt fyrir litlar tölur.
    s[s[0] = 1] = n;                                                            // Setjum það sem eftir er á hlaða.
    while (s[0] > 0)
    {
        ll k = s[s[0]--];                                                       // Tökum tölu af hlaðanum.
        if (miller_rabin(k)) a[c++] = k;                                        // Ef talan er frumtala þáttum við hana ekki frekar.
        else r = rho(k), s[++s[0]] = r, s[++s[0]] = k/r;                        // Þáttum töluna í tvennt og setjum hvorn þátt á hlaðann.
    }
    return c;
}

void test(ll x)
{
    ll i, r, a[200], m;
    printf("Factoring %lld...\n", x);
    m = pollard_rho(x, a);
    printf("The factors of %lld are: ", x); for (i = 0; i < m; i++) printf("%lld ", a[i]); printf("\n");
    for (i = 0; i < m; i++) if (!miller_rabin(a[i]))
    {
        printf("Miller-Rabin states that %lld is not a prime\n", a[i]);
        assert(0);
    }
    r = 1;
    for (i = 0; i < m; i++) r *= a[i];
    assert(r == x);
}

ll bigrand()
{
    ll r = rand(), s = rand();
    return r*RAND_MAX + s;
}

int main()
{
    srand(time(NULL));
    ll e = 10, x, i, j;
    eratos();
    while (1)
    {
        //scanf("%lld", &x);
        x = bigrand()%e + 1;
        if (e*10 < e) e = 10;
        else e *= 10;
        test(x);
        test(bigrand());
        x = p[rand()%pp];
        j = x;
        while (j*x > x)
        {
            test(j);
            j *= x;
        }
    }
}

