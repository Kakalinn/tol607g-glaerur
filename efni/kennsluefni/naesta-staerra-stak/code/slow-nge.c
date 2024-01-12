#include <stdio.h>

void nge(int* a, int* b, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i; j++) if (a[i] < a[i + j]) break;
        b[i] = (j == n - i ? -1 : i + j);
    }
}

int main()
{
    int n, i;
    scanf("%d", &n);
    int a[n], b[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    nge(a, b, n);
    for (i = 0; i < n; i++) printf("%3d ", a[i]); printf("\n");
    for (i = 0; i < n; i++) printf("%3d ", b[i]); printf("\n");
    return 0;
}
