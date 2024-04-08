#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;

typedef complex<double> pt;

int ccw(pt a, pt b, pt c)
{
    if (abs(a - b) < EPS || abs(imag((c - a)/(b - a))) < EPS) return 0;
    return imag((c - a)/(b - a)) > 0.0 ? 1 : -1;
}

pt piv;
int cmp(const void* p1, const void* p2)
{
    pt a = *(pt*)p1, b = *(pt*)p2;
    if (abs(arg(a - piv) - arg(b - piv)) > EPS)
        return arg(a - piv) < arg(b - piv) ? -1 : 1;
    if (abs(abs(a - piv) - abs(b - piv)) < EPS) return 0;
    return abs(a - piv) < abs(b - piv) ? -1 : 1;
}

int kuptur_hjupur(pt* p, pt* h, int n)                                          // Eftir á er h kúpti hjúpur p. Skilar stærð h.
{
    int i, j = 0, mn = 0;
    for (i = 1; i < n; i++)                                                     // Finnum punktinn sem er neðst til vinstri.
        if (imag(p[i] - p[mn]) < 0.0 || abs(imag(p[i] - p[mn])) < EPS
                && real(p[i] - p[mn]) < 0.0) mn = i;
    pt t = p[mn]; p[mn] = p[0]; p[0] = t; piv = p[0];                           // Látum vendipunktinn fremst.
    qsort(p + 1, n - 1, sizeof *p, cmp);                                        // Röðum eftir stefnuhorni.
    for (i = 1; i < n && abs(p[0] - p[i]) < EPS; i++);                          // Finnum fremsta punktinn sem er ekki jafn vendipunktinum.
    if (i == n) { h[j++] = p[0]; return j; }                                    // Allir punktarnir eru eins.
    h[j++] = p[n - 1], h[j++] = p[0], h[j++] = p[i];                            // Setjum aftast og fremstu tvo punktanna á hlaða.
    if (ccw(h[0], h[1], h[2]) == 0)                                             // Ef allir puntkarnir á hlaðanum liggja í línu eru allir punktarnir
        return j - (abs(h[0] - h[1]) < EPS ? 2 : 1);                            //   á línununni.
    for (i++; i < n;)                                                           // Ítrum í gegnum restina af punktunum.
        (ccw(h[j - 2], h[j - 1], p[i]) == 1) ? (h[j++] = p[i++]) : j--;         // Bætum punkta á hlaða ef hann myndir vinstri beygju, tökum annars af.
    return j - 1;                                                               // Skilum fjölda punkta á hlaðanum.
}

double ummal(pt* p, int n)                                                      // Reiknar ummál marghyrnings p.
{
    double r = 0.0;
    for (int i = 0; i < n; i++) r += abs(p[i] - p[(i + 1)%n]);                  // Leggjum saman fjarlægðirnar milli endapunktanna.
    return r;
}

char peek_stdin() { return ungetc(getchar(), stdin); }

int main()
{
    int m;
    double x, y;
    pt a[100], h[101];
    while (1)
    {
        int err, k = 0;
        while (1)
        {
            err = scanf("%lf%lf", &x, &y);
            if (err == -1) break;
            a[k++] = pt(x, y);
            if (peek_stdin() == 10) break;
        }
        if (err == -1) break;
        m = kuptur_hjupur(a, h, k);
        printf("%.8f\n", 100.0*k/(1.0 + ummal(h, m)));
    }
    return 0;
}
