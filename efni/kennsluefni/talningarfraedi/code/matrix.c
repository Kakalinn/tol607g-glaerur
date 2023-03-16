#include <stdio.h>
// Útfærsla á eindföldum ferningsfylkjaaðgerðum.

void addto(int* a, int* b, int n)
{ // a += b
    int i, j;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] += b[i*n + j];
}

void subfrom(int* a, int* b, int n)
{ // a -= b
    int i, j;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] -= b[i*n + j];
}

void multo(int* a, int* b, int n)
{ // a *= b
    int i, j, k, c[n][n];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) c[i][j] = 0;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) for (k = 0; k < n; k++)
        c[i][j] += a[i*n + k]*b[k*n + j];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] = c[i][j];
}

#if 0
3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1
#endif
int main()
{
    int i, j, n;
    scanf("%d", &n);                                                            // Innlestur hafinn.
    int a[n][n], b[n][n];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &b[i][j]);      // Innlestri lokið.

    addto(*a, *b, n);                                                           // Reiknum A + B.
    printf("A + B:\n");                                                         // Prentum A + B.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) printf("%3d ", a[i][j]);
        printf("\n");
    }
    subfrom(*a, *b, n);                                                         // Lögum A og B.
    subfrom(*a, *b, n);                                                         // Reiknum A - B.
    printf("A - B:\n");                                                         // Prentum A - B.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) printf("%3d ", a[i][j]);
        printf("\n");
    }
    addto(*a, *b, n);                                                           // Lögum A og B.
    multo(*a, *b, n);                                                           // Reiknum A*B.
    printf("A*B:\n");                                                           // Prentum A*B.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) printf("%3d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
