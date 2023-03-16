#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 10000
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
    return (x%m + m)%m;
}

ll f[MAXN], fm[MAXN];
ll prepare_nck(ll m)
{
    ll i;
    f[0] = 1;
    rep(i, MAXN) if (i != 0) f[i] = (f[i - 1]*i)%m;
    rep(i, MAXN) fm[i] = mulinv(f[i], m);
}

ll nck(ll n, ll k, ll m)
{
    return (((f[n]*fm[n - k])%m)*fm[k])%m;
}

ll d[MAXN][MAXN], m;
ll dp_lookup(ll x, ll y)
{
    if (d[x][y] != -1) return d[x][y];
    if (x < 1 || y < 0 || y > x) return 0;
    if (y == 0 || y == x) return 1;
    return d[x][y] = (dp_lookup(x - 1, y - 1) + dp_lookup(x - 1, y))%m;
}

int main()
{
    srand(time(NULL));
    ll a, b, i, j, n, k, q = -1;
    m = 3335561;
    rep(i, MAXN) rep(j, MAXN) d[i][j] = -1;
    prepare_nck(m);
    while (q--)
    {
        n = rand()%(MAXN - 3) + 1;
        k = rand()%(MAXN - 3) + 1;
        if (n > k) a = dp_lookup(n, k), b = nck(n, k, m);
        else a = dp_lookup(k, n), b = nck(k, n, m);
        assert(a == b);
    }
}
