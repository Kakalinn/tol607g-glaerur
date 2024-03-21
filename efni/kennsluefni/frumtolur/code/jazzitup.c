#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "battis.h"
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int main()
{
    int n = get_int();
    int i, j, e[n];
    rep(i, n) e[i] = 1;
    e[0] = e[1] = 0;
    rep(i, n) if (e[i])
    {
        if (n%i != 0)
        {
            printf("%d\n", i);
            return 0;
        }
        for (j = 2*i; j < n; j += i) e[j] = 0;
    }
    return 0;
}
