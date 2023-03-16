#include <stdio.h>
#define MAXN 1000000
typedef long long ll;

void swap(ll* x, ll* y) { ll s = *x; *x = *y; *y = s; }
ll egcd(ll a, ll b, ll* x, ll* y)
{
    if (b == 0)
    {
        *x = 1, *y = 0;
        return a;
    }
    ll r = egcd(b, a%b, x, y);
    *x -= a/b*(*y);
    swap(x, y);
    return r;
}

ll mulinv(ll a, ll m)
{
    ll x, y, g;
    g = egcd(a, m, &x, &y);
    return x;
}

ll f[MAXN], fm[MAXN];
ll prepare_nck(ll m)                                                            // ATH: m þarf að vera frumtala.
{
    ll i;
    for (i = 0; i < MAXN; i++) f[i] = (i == 0 ? 1 : (f[i - 1]*i)%m);            // Reiknum i!, fyrir öll i.
    for (i = 0; i < MAXN; i++) fm[i] = mulinv(f[i], m);                         // Reiknum margföldunarandhverfu i! m.t.t. frumtölu m, fyrir öll i.
}

ll nck(ll n, ll k, ll m)
{
    return (((f[n]*fm[n - k])%m)*fm[k])%m;                                      // Reiknum nCk eftir formúlu.
}

int main()
{
    ll n, k, m;
    scanf("%lld%lld%lld", &n, &k, &m);                                          // Innlestur.
    prepare_nck(m);                                                             // Upphafstillum gildin sem þarf.
    printf("%lld\n", nck(n, k, m));                                             // Reiknum og prentum svarið.
    return 0;
}
