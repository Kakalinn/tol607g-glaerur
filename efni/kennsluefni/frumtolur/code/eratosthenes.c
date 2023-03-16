#include <stdio.h>
typedef long long ll;
#define MAXN 1000000

ll e[MAXN];
void eratos()
{
    ll i, j;
    for (i = 0; i < MAXN; i++) e[i] = 1;                                        // Merkjum allar tölur sem 'óséðar'.
    e[0] = e[1] = 0;                                                            // Merkjum núll og einn sem 'samsettar'.
    for (i = 0; i < MAXN; i++) if (e[i] == 1)                                   // Ítrum í gegnum allar 'óséðar' tölur, og merkjum þær 'frumtölur'.
        for (j = i*i; j < MAXN; j += i) e[j] = 0;                               // Merkjum margfeldi af frumtölum sem 'samsettar'.
}

ll isp(ll x)                                                                    // Við þurfum að passa að kalla á eratos() áður en við köllum á isp(...).
{
    return e[x] == 1;                                                           // Flettum upp hvort x sé frumtala.
}

int main()
{
    ll i, n;
    scanf("%lld", &n);                                                          // Innlestur.
    eratos();                                                                   // Upphafstillum sigtið.
    for (i = 0; i < n; i++) if (isp(i)) printf("%d ", i);                       // Prentum allar frumtölurnar.
    printf("\n");
    return 0;
}
