#include <stdlib.h>
#include <stdio.h>
typedef long long ll;

#define CMP(E, F) (F <= E) - (E <= F)
int cmp(const void* p1, const void* p2)                                         // Samanburðarfall fyrir minnkandi röðun.
{
	return CMP(*(ll*)p2, *(ll*)p1);
}

int main()
{
	ll i, j, k, r = 0, n;
	scanf("%lld", &n);                                                          // Innlestur hefst.
	ll a[n], b[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);                               // Innlestri lokið.
	qsort(a, n, sizeof *a, cmp);                                                // Röðum tölunum svo eins tölur séu aðliggjandi.
	i = k = 0;
	while (i < n)                                                               // Teljum hversu oft hver tala kemur fyrir.
	{
		j = i;
		while (j < n && a[i] == a[j]) j++;
		b[k++] = j - i;
		i = j;
	}
	qsort(b, k, sizeof *b, cmp);                                                // Röðum til að finna algengstu stökin hratt.
	for (i = 0; i < k; i++) r += (i + 1)*b[i];                                  // Leggjum saman hversu oft hver tala er prentuð.
	printf("%lld\n", r);                                                        // Prentum svarið.
	return 0;
}
