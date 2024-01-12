#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define EPS 1e-9

typedef double complex pt;

double angle(pt a, pt o, pt b)                                                  // Fallið alpha(a, b, c) í glærunum.
{
    double r = fabs(carg(a - o) - carg(b - o));
    return r < M_PI ? r : 2*M_PI - r;
}

int ccw(pt a, pt b, pt c)                                                       // Fallið beta(a, b, c) í glærunum.
{
    if (cabs(a - b) < EPS || fabs(cimag((c - a)/(b - a))) < EPS) return 0;
    return cimag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

int is_in(pt* p, pt q, int n)                                                   // Er punkturinn q inni í marghyrningnum p?
{
    double s = 0.0;
    for (int i = 0, j = 1%n; i < n; i++, j = (i + 1)%n)
        s += ccw(q, p[i], p[j])*angle(p[i], q, p[j]);
    return fabs(s) > M_PI;
}

int is_on(pt* p, pt q, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        double a = creal(p[i]), b = creal(p[(i + 1)%n]);
        if (fmin(a, b) - EPS > creal(q) || creal(q) > fmax(a, b) + EPS) continue;
        a = cimag(p[i]), b = cimag(p[(i + 1)%n]);
        if (fmin(a, b) - EPS > cimag(q) || cimag(q) > fmax(a, b) + EPS) continue;
        if (ccw(p[i], q, p[(i + 1)%n]) == 0) return 1;
    }
    return 0;
}

int main()
{
    int i, q, n, x, y;
    scanf("%d", &n);
    while (n != 0)
    {
        pt a[n];
        for (i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            a[i] = x + y*I;
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d%d", &x, &y);
            if (is_on(a, x + I*y, n)) printf("on\n");
            else if (is_in(a, x + I*y, n)) printf("in\n");
            else printf("out\n");
        }
        scanf("%d", &n);
    }
    return 0;
}
