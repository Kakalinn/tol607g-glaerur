#include <stdio.h>
typedef long long ll;

ll modpow(ll x, ll n, ll m)
{ 
    ll r = 1;
    while (n > 0) 
    { 
        if (n%2 == 1) r = (r*x)%m; 
        n = n/2;
        x = (x*x)%m;   
    } 
    return r; 
}

ll mulinv(ll a, ll p)
{
    return modpow(a, p - 2, p);                                                 // Litla setning Fermat segir að þetta sé rétt svar ef p er frumtala.
}

int main()
{
    ll x, n, m, r = 1;
    scanf("%lld%lld%lld", &x, &n, &m);                                          // Innlestur. Við krefjumst þess að m sé frumtala.
    printf("%lld\n", modpow(x, n, m));                                          // Reiknum x^n mod m.
    return 0;
}
