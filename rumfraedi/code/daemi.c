#include <stdio.h>
#include <complex.h>
#include <assert.h>
typedef double complex pt;

int main()
{
	int n;
	double x, r = 0.0;
	pt p = 0;
	scanf("%d", &n);
	while (n--)
	{
		char c = getchar();
		while (c != 'f' && c != 'b' && c != 'l' && c != 'r') c = getchar();
		scanf("%lf", &x);
		if (c == 'f')      p += x*cexp(I*r);
		else if (c == 'b') p -= x*cexp(I*r);
		else if (c == 'l') r += x;
		else if (c == 'r') r -= x;
		else assert(0);
	}
	printf("%.8f\n", cabs(p));
	return 0;
}
