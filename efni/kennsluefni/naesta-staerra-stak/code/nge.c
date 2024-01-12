#include <stdio.h>

void nge(int* a, int* b, int n)                                                 // Eftir á inniheldur b vísi á næsta stak sem er stærra.
{
    int s[n], i;
    for (i = s[0] = 0; i < n; s[++s[0]] = i++)                                  // Ítrum í gegnum öll stökin.
        while (s[0] > 0 && a[s[s[0]]] < a[i]) b[s[s[0]--]] = i;                 // Tökum stök ofan af hlaðanum sem eru minni.
    while (s[0] > 0) b[s[s[0]--]] = -1;                                         // Í lokinn inniheldur hlaðin stökin sem hafa ekkert næsta stærra stak.
}

int main()
{
    int i, n;
    printf("Stærð listans: "); fflush(stdout);
    scanf("%d", &n);
    int a[n], b[n];
    printf("%d tölur: ", n); fflush(stdout);
    for (i = 0; i < n; i++) scanf("%d", &(a[i]));
    nge(a, b, n);
    printf("NGE:\n");
    for (i = 0; i < n; i++) printf("%8d ", a[i]); printf("\n");
    for (i = 0; i < n; i++) printf("%8d ", (b[i] != -1 ? a[b[i]] : -1)); printf("\n");
    return 0;
}
