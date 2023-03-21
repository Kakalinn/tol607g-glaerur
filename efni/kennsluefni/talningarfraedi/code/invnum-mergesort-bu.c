#include <stdio.h>
#include <stdlib.h>
typedef long long ll;
ll min(ll a, ll b) { return a < b ? a : b; }

ll teljum_umhverfingar(ll* a, ll n)                                             // a er umröðun, þ.e.a.s. inniheldur nákvæmlega 0, 1, ..., n - 1.
{                                                                               //   Fallið telur fjölda umhverfinga.
    ll t = 0, z = 0, i, j, c, e, l, m, r, b[2][n];
    for (i = 0; i < n; i++) b[t][i] = a[i];
    for (e = 1; e < n; e *= 2, t = 1 - t) for (l = 0; l < n; l += 2*e)
    {
        i = c = l, j = m = min(l + e, n), r = min(l + 2*e, n);
        while (i < m || j < r)
            if (i == m || (j < r && b[t][j] < b[t][i]))
                z += m - i, b[1 - t][c++] = b[t][j++];
            else b[1 - t][c++] = b[t][i++];
    }
    return z;
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
