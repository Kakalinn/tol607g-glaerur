#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 10000000
typedef long long ll;
typedef __int128 lll;

ll bigprod(ll x, ll y, ll m)
{
    return ((lll)x*y)%m;
}

ll modpow(ll x, ll n, ll m) 
{ 
    ll r;
    for (r = 1; n > 0; n = n/2, x = (x*x)%m) if (n&1) r = (r*x)%m;
    return r; 
}

int miller_rabin(ll n)                                                          // Ef fallið skilar 1 er n frumtala. Annars er n mjög líklega ekki
{                                                                               //   frumtala.
    if (n%2 == 0) return n == 2;
    if (n <= 3) return n == 3;
    ll a, x, i, k, s = 0, d = n - 1,
       t[12] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    while (d%2 == 0) d /= 2, s++;
    for (k = 0; k < 12; k++) if (t[k] <= n - 2)
    {
        a = t[k], x = modpow(a, d, n);
        if (x == 1 || x == n - 1) continue;
        for (i = 0; i < s - 1; i++) if ((x = bigprod(x, x, n)) == n - 1) break;
        if (i == s - 1) return 0;
    }
    return 1;
}

int e[MAXN];
void eratos()
{
    ll i, j;
    for (i = 0; i < MAXN; i++) e[i] = 1;
    e[0] = e[1] = 0;
    for (i = 0; i < MAXN; i++) if (e[i] == 1) for (j = i*i; j < MAXN; j += i) e[j] = 0;
}

#ifdef SIMPLE
int main()
{
    ll x;
    scanf("%lld", &x);
    printf("%s\n", miller_rabin(x) ? "It is a prime." : "It is not a prime.");
}
#else
int main()
{
    srand(time(NULL));
    printf("Building sieve\n");
    eratos();
    printf("Done building sieve\n");
    ll i, q = 10000000, s = 3;
    for (i = 0; i < q; i++) if (e[i] != miller_rabin(i))
    {
        printf("Failed at %d.\n", i);
        assert(0);
    }
    printf("No failure.\n");
}
#endif
