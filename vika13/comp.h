// daemi um algengan epsilon-slaka
#define EPS 1e-9

int eq(double a, double b)
{
	return fabs(a - b) < EPS;
}

int neq(double a, double b)
{
	return fabs(a - b) >= EPS;
}

