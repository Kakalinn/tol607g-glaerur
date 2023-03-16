#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
typedef long long ll;

ll modpow_rec(ll x, ll n, ll m)
{
    if (n == 0) return 1;
    ll r = modpow_rec(x, n/2, m);
    r = (r*r)%m;
    return n%2 == 0 ? r : (r*x)%m;
}

ll modpow(ll x, ll n, ll m) 
{ 
    ll r;
    for (r = 1; n > 0; n = n/2, x = (x*x)%m) if (n&1) r = (r*x)%m;
    return r; 
}

ll modpow_linear(ll x, ll n, ll m)
{
    ll r = 1;
    while (n--) r = (r*x)%m;
    return r;
}

int main()
{
    srand(time(NULL));
    ll x, y, m, q = 1000000;
    while (q--)
    {
        m = rand()%1000000, x = rand()%m, y = rand()%m;
        assert(modpow(x, y, m) == modpow_linear(x, y, m));
        assert(modpow_rec(x, y, m) == modpow_linear(x, y, m));
        printf("test done\n");
    }
    return 0;
}

