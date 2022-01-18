#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int cmp(const void* p1, const void* p2)
{
	ll x = *(ll*)p1, y = *(ll*)p2;
	return (y <= x) - (x <= y);
}

ll fjarlaegja_algengasta_stakid(ll *a, ll n)
{ // fjarlaegir algengasta stakid og skilar nyju lengd listans.
	ll i = 0, j, mx = 0, r;
	while (i < n)
	{ // finnum algengasta stakid i rodudu fylki.
		j = i;
		while (j < n && a[i] == a[j]) j++;
		if (mx < j - i) mx = j - i, r = a[i];
		i = j;
	}
	// fjarlaegjum algengasta stakid.
	for (i = 0, j = 0; i < n; i++) if (a[i] != r) a[j++] = a[i];
	return j;
}

int main()
{
	ll i, n, r = 0;
	scanf("%lld", &n);
	ll a[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	qsort(a, n, sizeof *a, cmp);
	while (n > 0)
	{
		r += n;
		n = fjarlaegja_algengasta_stakid(a, n);
	}
	printf("%lld\n", r);
	return 0;
}
