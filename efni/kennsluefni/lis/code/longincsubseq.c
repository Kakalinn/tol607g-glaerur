#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#define INF (1 << 30)
int max(int a, int b) { return a < b ? b : a; }

int lis(int *a, int *b, int n)
{
    int i, j, x, y;
    int d[n + 1], e[n];
    for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;
    for (i = 0; i < n; i++)
    {
        int r = -1, s;
        for (s = n + 1; s >= 1; s /= 2)
            while (r + s < n + 1 && d[r + s] < a[i]) r += s;
        d[r + 1] = a[i], e[i] = d[r];
    }
    for (x = n; d[x] == INF; x--);
    for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (a[i] == y)
        y = e[i], b[j--] = i;
    return x;
}

int main()
{
    int i, n;
    scanf("%d", &n);
    while (1)
    {
        int a[n], b[n];
        for (i = 0; i < n; i++) scanf("%d", &a[i]);
        int l = lis(a, b, n);
        printf("%d\n", l);
        for (i = 0; i < l; i++) printf("%d ", b[i]);
        printf("\n");
        if (scanf("%d", &n) == EOF) break;
    }
    return 0;
}
