#include <math.h>
#include <stdio.h>
#define EPS 1e-9

int eq(double a, double b)
{ // Eru |a| og |b| nogu likar?
	return fabs(a - b) < EPS;
}

int neq(double a, double b)
{ // Eru |a| og |b| nogu olikar?
	return fabs(a - b) >= EPS;
}

/*
0.1 0.2 0.3
*/
int main()
{
	double x, y, z;
	scanf("%lf%lf%lf", &x, &y, &z);
	printf("ep(%.6f + %.6f, %.6f) = %d\n", x, y, z, eq(x + y, z) ? 1 : 0);
	printf("%.6f + %.6f == %.6f = %d\n", x, y, z, x + y == z ? 1 : 0);
}
