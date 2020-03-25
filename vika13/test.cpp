#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
#include "gata.h"

int main()
{
	point r = foo(point(-1, 2), point(0, 0), point(1, 1));
	printf("%f %f\n", real(r), imag(r));
}
