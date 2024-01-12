#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define EPS 1e-9

typedef double complex pt;

int ccw(pt a, pt b, pt c)
{
    if (cabs(a - b) < EPS || fabs(cimag((c - a)/(b - a))) < EPS) return 0;
    return cimag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
int cmp(const void* p1, const void* p2)
{
    pt a = *(pt*)p1, b = *(pt*)p2;
    if (fabs(carg(a - piv) - carg(b - piv)) > EPS)
        return carg(a - piv) < carg(b - piv) ? -1 : 1;
    if (fabs(cabs(a - piv) - cabs(b - piv)) < EPS) return 0;
    return cabs(a - piv) < cabs(b - piv) ? -1 : 1;
}

int kuptur_hjupur(pt* p, pt* h, int n)                                          // Eftir á er h kúpti hjúpur p. Skilar stærð h.
{
    int i, j = 0, mn = 0;
    for (i = 1; i < n; i++)                                                     // Finnum punktinn sem er neðst til vinstri.
        if (cimag(p[i] - p[mn]) < 0.0 || fabs(cimag(p[i] - p[mn])) < EPS
                && creal(p[i] - p[mn]) < 0.0) mn = i;
    pt t = p[mn]; p[mn] = p[0]; p[0] = t; piv = p[0];                           // Látum vendipunktinn fremst.
    qsort(p + 1, n - 1, sizeof *p, cmp);                                        // Röðum eftir stefnuhorni.
    for (i = 1; i < n && cabs(p[0] - p[i]) < EPS; i++);                         // Finnum fremsta punktinn sem er ekki jafn vendipunktinum.
    if (i == n) { h[j++] = p[0]; return j; }                                    // Allir punktarnir eru eins.
    h[j++] = p[n - 1], h[j++] = p[0], h[j++] = p[i];                            // Setjum aftast og fremstu tvo punktanna á hlaða.
    if (ccw(h[0], h[1], h[2]) == 0)                                             // Ef allir puntkarnir á hlaðanum liggja í línu eru allir punktarnir
        return j - (cabs(h[0] - h[1]) < EPS ? 2 : 1);                           //   á línununni.
    for (i++; i < n;)                                                           // Ítrum í gegnum restina af punktunum.
        (ccw(h[j - 2], h[j - 1], p[i]) == 1) ? (h[j++] = p[i++]) : j--;         // Bætum punkta á hlaða ef hann myndir vinstri beygju, tökum annars af.
    return j - 1;                                                               // Skilum fjölda punkta á hlaðanum.
}

#if 0
9
-1 1
0 1
1 1
-1 0
0 0
1 0
-1 -1
0 -1
1 -1
#endif

int main()
{
    int i, n, m, x, y;
    scanf("%d", &n);
    while (n != 0)
    {
        pt a[n], h[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            a[i] = x + y*I;
        }
        m = kuptur_hjupur(a, h, n);
        printf("%d\n", m);
        for (i = 0; i < m; i++) printf("%d %d\n", (int)creal(h[i]), (int)cimag(h[i]));
        scanf("%d", &n);
    }
    return 0;
}
