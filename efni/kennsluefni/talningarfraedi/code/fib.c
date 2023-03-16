#include <stdio.h>
#define MOD 1000000009
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

int fib(ll n)                                                                   // Reiknar n-tu Fibonacci töluna.
{
    ll a[2][2] = {{1, 1}, {1, 0}};                                              // Upphafstillum fylki fyrir rakningarvenslin.
    if (n == 1 || n == 2) return 1;                                             // Prentum upphafsgildin.
    matpow(*a, n - 2, 2);                                                       // Reiknum n - 2 veldið af flykinu.
    return (a[0][0] + a[0][1])%MOD;                                             // Margföldum efstu línuna í fylkinu við upphfsgildin og skilum.
}

int main()
{
    int n;
    scanf("%lld", &n);                                                          // Innlestur.
    printf("%lld\n", fib(n));                                                   // Reiknum og prentum svarið.
    return 0;
}

