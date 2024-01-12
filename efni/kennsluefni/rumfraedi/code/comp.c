#include <math.h>
#include <stdio.h>
#define EPS 1e-9

int eq(double a, double b)  { return fabs(a - b) <  EPS; }                      // Eru a og b nógu líkar?
int neq(double a, double b) { return fabs(a - b) >= EPS; }                      // Eru a og b nógu ólíkar?

int main()
{
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("eq(%.2f + %.2f, %.2f) = %d\n", x, y, z, eq(x + y, z) ? 1 : 0);
    printf("(%.2f + %.2f == %.2f) = %d\n", x, y, z, x + y == z ? 1 : 0);
    return 0;
}
