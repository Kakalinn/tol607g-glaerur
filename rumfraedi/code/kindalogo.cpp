int main()
{
	double x, r = 0.0;
	pt p(0.0, 0.0);
	int n = get_int();
	while (n-- != 0)
	{
		char c = getchar();
		x = get_int();
		if (c == 'f')      p += x*exp(pt(0.0, r));
		else if (c == 'b') p -= x*exp(pt(0.0, r));
		else if (c == 'l') r += x;
		else if (c == 'r') r -= x;
	}
	printf("%.8f\n", abs(p));
	return 0;
}
