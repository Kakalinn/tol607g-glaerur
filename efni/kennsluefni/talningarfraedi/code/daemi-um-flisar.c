#include <stdio.h>
#define MOD 1000000007
typedef long long ll;

void multo(ll* a, ll* b, ll n)
{ // a *= b
    ll i, j, k, c[n][n];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) c[i][j] = 0;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) for (k = 0; k < n; k++)
        c[i][j] = (c[i][j] + (a[i*n + k]*b[k*n + j])%MOD)%MOD;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] = c[i][j];
}

void matpow(ll* a, ll p, ll n)
{ // a = a^p
    ll r[n][n], i, j;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) r[i][j] = 0;
    for (i = 0; i < n; i++) r[i][i] = 1;
    while (p > 0)
    {
        if (p%2 == 1) multo(*r, a, n);
        p /= 2;
        multo(a, a, n);
    }
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] = r[i][j];
}

int main()
{
    ll i, j, n, r = 0, a[8][8] =
    {
        {1, 1, 1, 0, 1, 1, 0, 0},                                               // Forreiknað fylki, sjá glærur.
        {1, 0, 1, 0, 1, 0, 0, 0},
        {1, 1, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };
    scanf("%lld", &n);                                                          // Innlestur.
    matpow(*a, n - 1, 8);                                                       // Hefjum fylkið í n - 1 veldi.
    for (i = 0; i < 8; i++) for (j = 0; j < 8; j++)
        if (i != 3 && i != 6 && i != 7) r = (r + a[i][j])%MOD;                  // Leggjum saman alla mögulegu vegina.
    printf("%lld\n", r);                                                        // Prentum summuna.
    return 0;
}
