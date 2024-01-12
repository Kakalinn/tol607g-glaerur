#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <assert.h>
#define EPS 1e-9

typedef double complex pt;

double flatarmal(pt* p, int n)                                                  // Reiknar flatarmál marghyrnings p.
{
    double r = 0.0;
    for (int i = 0, j = 1%n; i < n; i++, j = (i + 1)%n)
        r += creal(p[i])*cimag(p[j]) - creal(p[j])*cimag(p[i]);                 // Sjá glærur.
    return fabs(0.5*r);
}

double ummal(pt* p, int n)                                                      // Reiknar ummál marghyrnings p.
{
    double r = 0.0;
    for (int i = 0; i < n; i++) r += cabs(p[i] - p[(i + 1)%n]);                 // Leggjum saman fjarlægðirnar milli endapunktanna.
    return r;
}

int main()
{
    int i, n, x, y;
    scanf("%d", &n);
    pt a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        a[i] = x + y*I;
    }
    printf("Ummalid er %.8f.\n", ummal(a, n));
    printf("Flatarmalid er %.8f.\n", flatarmal(a, n));
    return 0;
}
