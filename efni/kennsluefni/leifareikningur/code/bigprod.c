#include <stdio.h>
typedef long long ll;
typedef __int128 lll;

ll bigprod(ll x, ll y, ll m)
{
    return ((lll)x*y)%m;                                                        // Breytum tagi x í 128 bit tölu þannig að x*y overflowi ekki.
}


// Prófið þetta input:
//  9223372036854775807 9223372036854775807 9223372036854775801
int main()
{
    ll x, y, m;
    scanf("%lld%lld%lld", &x, &y, &m);                                          // Innlestur.
    printf("%lld\n", (x*y)%m);                                                  // Reiknum leyfina á x*y mod m, með overflow (vitlaust svar).
    printf("%lld\n", bigprod(x, y, m));                                         // Reiknum leyfina á x*y mod m (rétt svar).
}
