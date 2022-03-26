#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <assert.h>
#define EPS 1e-9

typedef double complex pt;

double flatarmal(pt* p, int n)
{ // p[0] == p[n - 1]
	int i;
	double r = 0.0;
	for (i = 0; i < n - 1; i++)
		r += creal(p[i])*cimag(p[i + 1]) - creal(p[i + 1])*cimag(p[i]);
	return fabs(0.5*r);
}

double ummal(pt* p, int n)
{ // p[0] == p[n - 1]
	int i;
	double r = 0.0;
	for (i = 0; i < n - 1; i++) r += cabs(p[i] - p[i + 1]);
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
	assert(cabs(a[0] - a[n - 1]) < EPS);
	printf("Ummalid er %.8f.\n", ummal(a, n));
	printf("Flatarmalid er %.8f.\n", flatarmal(a, n));
	return 0;
}
