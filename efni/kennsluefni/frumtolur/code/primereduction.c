#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#define getchar() fgetc_unlocked(stdin)
#define irep(E, F) for (int E = 0; E < (F); E++)
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
typedef long long ll;
ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

ll get_int()
{
    ll r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}

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

ll miller_rabin(ll n)
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

int main()
{
    ll i, a[200], n = get_int();
    while (n != 4)
    {
        ll r = 0, m = 0;
        while (m != 1)
        {
            r++;
            m = pollard_rho(n, a);
            n = 0;
            rep(i, m) n += a[i];
        }
        printf("%lld %lld\n", a[0], r);
        n = get_int();
    }
    return 0;
}
