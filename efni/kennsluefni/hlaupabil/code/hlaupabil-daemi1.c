#include <stdio.h>

int main()
{
    int n, k, i;
    scanf("%d%d", &n, &k);                                                      // Innlestur hefst.
    int a[n];
    for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
    int b = 0, z = 0, mx = 0;
    for (i = 0; i < n; i++)                                                     // Ítrum í gegnum öll stökin og stækkum hlaupabilið að aftan.
    {
        if (a[i] == 0) z++;                                                     // Leiðréttum talninguna okkar á fjölda núlla.
        while (z > k) if (a[b++] == 0) z--;                                     // Tökum stök framan úr hlaupabilinu á meðan fjöldi núlla er of mikill.
        if (i - b + 1 > mx) mx = i - b + 1;                                     // Leiðréttum besta svarið ef þörf er á.
    }
    printf("%d\n", mx);                                                         // Prentum svarið.
    return 0;
}
