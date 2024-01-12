#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
typedef complex double pt;

int cmpx(const void* p1, const void* p2)                                        // Samaburðarfall til að raða punktum eftir vaxandi y-hniti.
{
    double a = creal(*(pt*)p1), b = creal(*(pt*)p2);
    if (fabs(a - b) < 1e-9) return 0;
    if (a < b) return -1;
    return 1;
}

void merge(pt* a, pt *b, int m, int r)                                          // Þetta er eins og í deila og drottna glærunum.
{
    int i = 0, j = m, c = 0;
    while (i < m && j < r) b[c++] = a[cimag(a[j] - a[i]) < 0.0 ? j++ : i++];
    while (i < m || j < r) b[c++] = a[j < r ? j++ : i++];
    for (i = 0; i < r; i++) a[i] = b[i];
}

double closest_pair_r(pt *a, pt *b, pt *c, int n, pt *r1, pt *r2)               // Endurkvæmt hjálparfall.
{
    if (n < 2) { b[0] = a[0]; return 1e16; }                                    // Grunntilvik.
    int m = n/2, i, j, k = 0;
    pt r3, r4;
    double p = closest_pair_r(a, b, c, m, r1, r2), d;                           // Reiknum svarið fyrir vinstri helming.
    b[m] = a[m];
    d = closest_pair_r(a + m + 1, b + m + 1, c + m + 1, n - m - 1, &r3, &r4);   // Reiknum svarið fyrir hægri helming.
    if (d < p) p = d, *r1 = r3, *r2 = r4;                                       // Veljum betra svarið.
    merge(b, c, m, m + 1), merge(b, c, m + 1, n);                               // Röðum jafnóðum eftir y-hniti með merge sort.
    for (i = 0; i < n; i++) if (fabs(creal(b[i] - a[m])) < p) c[k++] = b[i];    // Finnum punktana með x-hnit á bilinu [x0 - d, x0 + d], sjá glærur.
    for (i = 0; i < k; i++)                                                     // Finnum minnstu fjarlægðina milli punktanna milli helminganna.
        for (j = i + 1; cimag(c[j] - c[i]) < p && j < k; j++)                   // Rúmfræðin segir okkur að þessi lykkja keyrir sjaldnar en sjö sinnum.
            if (cabs(c[i] - c[j]) < p)
                p = cabs(c[i] - c[j]), *r1 = c[i], *r2 = c[j];
    return p;                                                                   // Skilum svarinu.
}

double closest_pair(pt* a, int n, pt* r1, pt* r2)                               // Skilar lengd milli nálægustu punkta í a: x og y.
{
    pt b[n], c[n];
    qsort(a, n, sizeof *a, cmpx);                                               // Röðum eftir vaxandi x-hniti.
    return closest_pair_r(a, b, c, n, r1, r2);                                  // Reiknum og skilum svarinu.
}

int main()
{
    int i, n;
    scanf("%d", &n);
    while (n != 0)
    {
        pt a[n], x, y;
        for (i = 0; i < n; i++)
        {
            double x, y;
            scanf("%lf%lf\n", &x, &y);
            a[i] = x + I*y;
        }
        closest_pair(a, n, &x, &y);
        printf("%.8f %.8f %.8f %.8f\n", creal(x), cimag(x), creal(y), cimag(y));
        scanf("%d", &n);
    }
    return 0;
}

