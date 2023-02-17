#include <stdio.h>

#define EPS 1e-9
double f(double x)
{
	return 5.0 - 1.2*x + 0.1*x*x;
}

int main()                                                                      // Finnur lággildi kúpta fallsins f á bilinu [a, b].
{
	double a = 1.0, b = 10.0, m1, m2;
	while (b - a > EPS)                                                         // Þriðjungaleit hefst.
	{
		m1 = (a + a + b)/3.0, m2 = (a + b + b)/3.0;                             // Skiptum í þriðjunga.
		if (f(m1) > f(m2)) a = m1;                                              // Skerum burt neðri þriðjunginn.
		else b = m2;                                                            // Skerum burt efri þriðjunginn.
	}
	printf("f(%.2f) = %.2f\n", a, f(a));                                        // Prentum lággildið.
	return 0;
}
