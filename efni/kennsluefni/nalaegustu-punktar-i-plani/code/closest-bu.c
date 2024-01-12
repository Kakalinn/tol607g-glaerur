#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>
#define MAXN 1000000
int min(int a, int b) { return a < b ? a : b; }
typedef complex double pt;

int cmpx(const void* p1, const void* p2)                                        // Samanburðarfall til að raða punktum eftir vaxandi x-hniti.
{
    double a = creal(*(pt*)p1), b = creal(*(pt*)p2);
    if (fabs(a - b) < 1e-9) return 0;
    if (a < b) return -1;
    return 1;
}

double closest_pair(pt *a, int n, pt *x, pt *y)                                 // Skilar lengd milli nálægustu punkta í a: x og y.
{
    double p[n];
    int i, j, k, l, m, e, r;
    pt b[n], c[n], z[n], w[n];
    qsort(a, n, sizeof(a[0]), cmpx);                                            // Röðum eftir vaxandi x-hniti.
    for (i = 0; i < n; i++) b[i] = a[i], p[i] = 1e16;                           // Upphafstillum öll hlutsvörin.
    for (e = 1; e < n; e *= 2) for (l = 0; l + e < n; l += 2*e)                 // Sameinum hlutsvörin.
    {
        i = k = l, j = m = min(l + e, n), r = min(l + e*2, n);
        while (i < m && j < r)
            c[k++] = b[cimag(b[j] - b[i]) < 0.0 ? j++ : i++];
        while (i < m || j < r) c[k++] = b[j < r ? j++ : i++];
        for (i = l; i < r; i++) b[i] = c[i];                                    // Röðum eftir vaxandi y-hniti með mergesort jafnóðum.
        if (p[m] < p[l]) p[l] = p[m], z[l] = z[m], w[l] = w[m];                 // Veljum betra hlutsvar af hvorum helmingnum.
        for (k = 0, i = l; i < r; i++) if (fabs(creal(b[i] - a[m])) < p[l])     // Finnum puktana með x-hnit á bilinu [x0 - d, x0 + d], sjá glærur.
            c[k++] = b[i];
        for (i = 0; i < k; i++)                                                 // Finnum minnstu fjarlægðina milli punktanna milli helminganna.
            for (j = i + 1; cimag(c[j] - c[i]) < p[l] && j < k; j++)            // Rúmfræðin segir okkur að þessi lykkja keyrir sjaldnar en sjö sinnum.
                if (cabs(c[i] - c[j]) < p[l])
                    p[l] = cabs(c[i] - c[j]), z[l] = c[i], w[l] = c[j];
    }
    *x = z[0], *y = w[0];
    return p[0];                                                                // Skilum svarinu.
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

