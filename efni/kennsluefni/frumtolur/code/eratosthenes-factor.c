#include <stdio.h>
#define MAXN 1000000

int e[MAXN];
void eratos()
{
    int i, j;
    for (i = 0; i < MAXN; i++) e[i] = 0;                                        // Merkjum allar tölur óséðar.
    e[0] = e[1] = -1;                                                           // Núll og einn hafa ekki þætti stærri en 1.
    for (i = 0; i < MAXN; i++) if (e[i] == 0)                                   // Ítrum í gegnum þær tölur sem við eigum eftir að gera (frumtölur).
        for (j = i; j < MAXN; j += i) e[j] = i;                                 // Merkjum þættina.
}

void factor(int x)
{
    if (x < 2) return;
    printf("%d ", e[x]);                                                        // Prentum frumþáttinn.
    factor(x/e[x]);                                                             // Frumþáttum restina.
}

int isp(int x)
{
    return e[x] == x;                                                           // Talan er frumtala ef eini þátturinn stærri en 1 er talan sjálf.
}

int main()
{
    int i, n;
    eratos();
    while (scanf("%d", &n) != EOF)                                              // Lesum inn tölu.
    {
        if (isp(n)) printf("The number %d is prime.\n", n);                     // Talan er frumtala.
        else printf("The number %d is composite.\n", n);                        // Talan er samsett.
        printf("It's factors are: ");
        factor(n);                                                              // Prentum þættina.
        printf("\n");
    }
    return 0;
}
