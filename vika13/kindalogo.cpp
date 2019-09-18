int main()
{
	double pi = acos(-1);
	point p(0.0, 0.0);
	double x, r = 0.0;
	int i, n = get_int();
	for (i = 0; i < n; i++)
	{
		char c = getchar();
		x = get_int();

		if (c == 'f')      p = p + x*exp(r*point(0.0, 1.0));
		else if (c == 'b') p = p + x*exp((r + pi)*point(0.0, 1.0));
		else if (c == 'r') r = r - pi*x/180.0;
		else if (c == 'l') r = r + pi*x/180.0;
	}
	printf("%.8f\n", abs(p));
	return 0;
}
