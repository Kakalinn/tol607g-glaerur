#include <stdio.h>
#include <complex.h>
typedef double complex pt;

int main()
{
    int n;
    double x, r = 0.0;
    pt p = 0;
    scanf("%d", &n);                                                            // Innlestur.
    while (n--)                                                                 // Lesum allar skipanirnar.
    {
        char c = getchar();
        while (c != 'f' && c != 'b' && c != 'l' && c != 'r') c = getchar();     // Lesum tegundina af skipuninni.
        scanf("%lf", &x);                                                       // Lesum viðfang skipunarinnar.
        if (c == 'f')      p += x*cexp(I*r);                                    // Löbbum áfram.
        else if (c == 'b') p -= x*cexp(I*r);                                    // Löbbum aftur á bak.
        else if (c == 'l') r += x;                                              // Begyjum til vinstri.
        else if (c == 'r') r -= x;                                              // Begyjum til hægri.
    }
    printf("%.8f\n", cabs(p));                                                  // Prentum fjarlægðina frá upphafspunktinum.
    return 0;
}
