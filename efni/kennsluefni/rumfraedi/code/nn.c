#include <stdio.h>
#include <math.h>

int main()
{
    double n, r, theta, omega;
    scanf("%lf%lf", &n, &r);
    theta = 2*M_PI/n;
    omega = (M_PI - theta)/2.0;
    printf("%.8f\n", (r*sin(theta))/(2*sin(omega) - sin(theta)));
    return 0;
}
