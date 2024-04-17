#include <stdio.h>
typedef long long ll;

void factor(ll x)
{
    for (ll i = 2; i*i <= x;)
    {
        if (x%i == 0) printf("%lld ", i), x /= i;                               // i er þáttur. Við megum ekki stækka i því i gæti gengið ofta upp í x.
        else i++;                                                               // i er ekki þáttur, stækkum i.
    }
    printf("%lld\n", x);                                                        // Við eigum einn þátt eftir í lokinn.
}

int main()
{
    ll x;
    scanf("%lld", &x);                                                          // Innlestur.
    factor(x);                                                                  // Frumþáttum töluna.
    return 0;
}

