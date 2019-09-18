// Skerast [a, b] og [c, d]?
bool bxb(double a, double b, double c, double d)
{
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return fmax(a,c) <= fmin(b,d);
}
