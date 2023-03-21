#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

ll merge(ll* a, ll *b, ll l, ll m, ll r)
{
    ll i = l, j = m, c = i, z = 0;
    while (i < m || j < r)
        if (i == m || (j < r && a[j] < a[i])) z += m - i, b[c++] = a[j++];
        else b[c++] = a[i++];
    for (i = l; i < r; i++) a[i] = b[i];
    return z;
}

ll mergesort(ll* a, ll *b, ll l, ll r)
{
    if (r - l < 2) return 0;                                                    // Tómur listar og einstökungar eru raðaðir.
    ll m = (l + r)/2, z = mergesort(a, b, l, m) + mergesort(a, b, m, r);        // Helmingum og röðum hvorum helming.
    return z + merge(a, b, l, m, r);                                            // Sameinum helmingana og skilum.
}

ll teljum_umhverfingar(ll* a, ll n)                                             // a er umröðun, þ.e.a.s. inniheldur nákvæmlega 0, 1, ..., n - 1.
{                                                                               //   Fallið telur fjölda umhverfinga.
    ll b[n];
    return mergesort(a, b, 0, n);
}

#if 0
7
4 1 6 5 7 3 2
#endif
int main()
{
    ll n, i;
    scanf("%lld", &n);                                                          // Innlestur hafinn.
    ll a[n];
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);                               // Innlestri lokið.
    printf("%lld\n", teljum_umhverfingar(a, n));                                // Reiknum og prentum svarið.
    return 0;
}
