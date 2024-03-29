#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define EPS 1e-9
typedef double complex pt;

int bxb(double a, double b, double c, double d)                                 // Skerast bilin [a, b] og [c, d]?
{
    if (a > b) return bxb(b, a, c, d);
    if (c > d) return bxb(a, b, d, c);                                          // Göngum úr skugga um að a <= b og c <= d.
    return fmax(a, c) < fmin(b, d) + EPS;
}

int ccw(pt a, pt b, pt c)                                                       // Í hvora áttina er verið að beygja?
{
    double f = cimag((c - a)/(b - a));
    if (fabs(f) < EPS) return 0;
    return f < EPS ? -1 : 1;
}

int lxl(pt a, pt b, pt c, pt d)                                                 // Skerast línustrikin <a, b> og <c, d>?
{
    int a1 = ccw(a, b, c), a2 = ccw(a, b, d),
        a3 = ccw(c, d, a), a4 = ccw(c, d, b);
    if (a1*a2*a3*a4 == 0) return 0;                                             // Þessi lína er almennt ekki rétt en virkar fyrir l2l(...).
    if (a1*a2 != -1 || a3*a4 != -1) return 0;
    return bxb(creal(a), creal(b), creal(c), creal(d))
        && bxb(cimag(a), cimag(b), cimag(c), cimag(d));
}

double p2l(pt p, pt l1, pt l2)                                                  // Finnur fjarlægð frá punkti í línustrik.
{
    p = (p - l1)*cexp(-I*carg(l2 - l1));                                        // Hliðrum og snúum þannig að l1 = 0 og Im l2 = 0.
    if (-EPS < creal(p) && creal(p) < cabs(l2 - l1) + EPS)
        return fabs(cimag(p));
    return fmin(cabs(p), cabs(p - cabs(l2 - l1)));
}

double l2l(pt a1, pt a2, pt b1, pt b2)                                          // Finnur fjarlægð milli línustrikanna <a1, a2> og <b1, b2>.
{
    if (cabs(a1 - a2) < EPS && cabs(b1 - b2) < EPS) return cabs(a1 - b1);       // Bæði línustrikin eru punktar.
    if (cabs(a1 - a2) < EPS) return p2l(a1, b1, b2);                            // Fyrra línustrikið er punktur.
    if (cabs(b1 - b2) < EPS) return p2l(b1, a1, a2);                            // Seinna línustrikið er punktur.
    if (lxl(a1, a2, b1, b2)) return 0.0;                                        // Ef línustrikin skerast er fjarlægðin á milli núll.
    return fmin(fmin(p2l(a1, b1, b2), p2l(a2, b1, b2)),                         // Skoðum fjarlægðina frá endapunktunum í hitt línustrikið.
            fmin(p2l(b1, a1, a2), p2l(b2, a1, a2)));
}


#if 0
1871 5789 216 -517 189 -1518 3851 1895
#endif
int main()
{
    pt p[4];
    int i, x, y, t;
    scanf("%d", &t);
    while (t--)
    {
        for (i = 0; i < 4; i++)
        {
            scanf("%d%d", &x, &y);
            p[i] = x + I*y;
        }
        double r = l2l(p[0], p[1], p[2], p[3]);
        if (r == 0.0) r = 0.0; // Passar ad prenta ekki "-0.000000"
        printf("%.2f\n", r);
    }
    return 0;
}

