#include <stdio.h>

int gradugt_check(int *x, int n, int k, int m)                                  // Gáum gráðugt hvort kisunum megi raða með m millibili.
{
    int i, j, r = 0;
    for (i = 0, j = -2*m; i < n; i++) if (x[i] >= j) j = x[i] + m, r++;         // Látum kisu lengst til vinstri, síðan á næsta löglega reit, o.s.frv..
    return r >= k;                                                              // Skilum hvort við náum að raða öllum köttunu.
}

int main()
{
    int i, r, s, n, k;
    scanf("%d%d", &n, &k);                                                      // Innlestur hefst.
    int x[n];
    for (i = 0; i < n; i++) scanf("%d", &x[i]);                                 // Innlestri lokið.
    r = 0, s = 1000000000;
    while (r < s)                                                               // Helmingunarleit hefst.
    {
        int m = (r + s)/2;                                                      // Helmingum.
        if (gradugt_check(x, n, k, m)) r = m + 1;                               // Hendum burt neðri helmingnum.
        else s = m;                                                             // Hendum burt efri helmingnum.
    }
    printf("%d\n", r - 1);                                                      // Prentum svarið.
    return 0;
}
