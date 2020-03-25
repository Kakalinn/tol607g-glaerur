#include <math.h>
#include <stdio.h>
#define EPS 1e-9

#include "comp.h"

int main()
{
	while (1)
	{
		double a, b;
		scanf("%lf %lf", &a, &b);
		if (eq(a, b)) printf("%.4f = %.4f\n", a, b);
		if (neq(a, b)) printf("%.4f =/= %.4f\n", a, b);
		if (less_than(a, b)) printf("%.4f < %.4f\n", a, b);
		if (less_than_or_eq(a, b)) printf("%.4f <= %.4f\n", a, b);
		if (greater_than(a, b)) printf("%.4f > %.4f\n", a, b);
		if (greater_than_or_eq(a, b)) printf("%.4f >= %.4f\n", a, b);
	}
}
