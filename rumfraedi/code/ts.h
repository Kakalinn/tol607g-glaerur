// lagmorkum fall f a bili [a, b]
double l = a, r = b;
while (r - l > EPS)
{
	m1 = l + (r - l)/3.0;
	m2 = r - (r - l)/3.0;
	if (f(m1) > f(m2)) l = k1;
	else r = k2;
}
// nu er f(r) lagildi f á [a, b]
