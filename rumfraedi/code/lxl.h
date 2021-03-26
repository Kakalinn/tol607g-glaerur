// Skilar attun á þrihyrningnum stikuðum með <a, b, c, a>
int sgnarea(pt a, pt b, pt c)
{
	double f = imag((c - a)/(b - a));
	if (fabs(f) < EPS) return 0;
	if (f < EPS) return -1;
	return 1;
}

// Skerast <a, b> og <c, d>?
int lxl(pt a, pt b, pt c, pt d)
{
	int a1 = sgnarea(a, b, c), a2 = sgnarea(a, b, d),
	    a3 = sgnarea(c, d, a), a4 = sgnarea(c, d, b);
	if (a1*a2*a3*a4 == 0) return 0; // ATH: virkar almennt ekki
	if (a1*a2 != -1 || a3*a4 != -1) return 0;
	return bxb(real(a), real(b), real(c), real(d))
		&& bxb(imag(a), imag(b), imag(c), imag(d));
}
