#include <stdlib.h>
#include <stdio.h>
typedef struct { int x, y; } ii;
int cmp(const void* p1, const void* p2) { return ((ii*)p1)->x - ((ii*)p2)->x; } // Samanburðar fall til að raða pari eftir fyrra stakinu.

int main()
{
    int n, r, i, j, k;
    scanf("%d", &n);                                                            // Innlestur hefst.
    ii a[2*n];
    int b[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &(a[2*i].x), &(a[2*i + 1].x));
        a[2*i].y = i; a[2*i + 1].y = i; b[i] = 0;                               // Innlestri lokið.
    }
    qsort(a, 2*n, sizeof *a, cmp);                                              // Röðum endapunktunum.
    i = 0, r = 0;
    while (i < 2*n)                                                             // Ítrum í gegnum endapunktanna.
    {
        k = 1, j = i + 1, b[a[i].y] = 1;                                        // Merkjum bilið sem við erum að skoða 'séð' og setjum í hlaupabilið.
        while (k > 0)                                                           // Á meðan hlaupabilið er ekki tómt ítrum við í gegnum bilin.
        {
            if (b[a[j].y] == 1) k--;                                            // Ef við höfum séð þetta bil áður erum við að skoða hægri endapunkt.
            else b[a[j].y] = 1, k++;                                            // Annars erum við að skoða vinstri endapunkt.
            j++;
        }
        r = r + a[j - 1].x - a[i].x; i = j;                                     // Uppfærum heildarsummuna.
    }
    printf("%d\n", r);                                                          // Prentum svarið.
    return 0;
}
