#include <stdio.h>
typedef long long ll;

int isp(ll x)
{
    if (x < 2) return 0;                                                        // Núll og einn eru ekki frumtölur.
    for (ll i = 2; i*i <= x; i++) if (x%i == 0) return 0;                       // Prófum tölur til og með sqrt(n).
    return 1;                                                                   // Við fundum engan þátt svo x er frumtala.
}

int main()
{
    ll x;
    while (scanf("%lld", &x) != EOF)                                            // Lesum inn tölur.
    {
        if (isp(x)) printf("%lld\n", x);                                        // Prentum töluna ef hún er frumtala á staðalúttak.
        else fprintf(stderr, ">> %lld is not a prime\n", x);                    // Prentum töluna ef hún er samsett á stderr.
    }
    return 0;
}

