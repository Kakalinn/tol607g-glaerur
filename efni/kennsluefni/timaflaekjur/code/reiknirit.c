#include <stdio.h>
#include <stdlib.h>
typedef long long ll;

int cmp(const void *p1, const void *p2)
{
	ll x = *(ll*)p1, y = *(ll*)p2;
	return (y <= x) - (x <= y);
}

ll fjarlaegja_algengasta_stakid(ll *a, ll n)                                    // Fjarlægir algengasta stakið og skilar nýju lengd listans.
{
	ll i, j, mx, r;
	for (i = j = mx = 0; i < n; i = j)                                          // Finnum algengasta stakið i röðuðu fylki.
	{
		while (j < n && a[i] == a[j]) j++;                                      // Teljum hversu oft a[i] er í flykinu.
		if (mx < j - i) mx = j - i, r = a[i];                                   // Uppfærum besta stakið hingað til ef þörf er á.
	}
	for (i = 0, j = 0; i < n; i++) if (a[i] != r) a[j++] = a[i];                // Fjarlægjum algengasta stakið.
	return j;
}

int main()
{
	ll i, n, r = 0;
	scanf("%lld", &n);                                                          // Innlestur.
	ll a[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);                               // Innlestri lokið.
	qsort(a, n, sizeof *a, cmp);                                                // Röðum inntakinu.
	while (n > 0)
	{
		r += n;                                                                 // "Prentum" allt sem er ennþá í listanum.
		n = fjarlaegja_algengasta_stakid(a, n);                                 // Fjarlægjum algengasta stakið í listanum.
	}
	printf("%lld\n", r);                                                        // Prentum svarið.
	return 0;
}
