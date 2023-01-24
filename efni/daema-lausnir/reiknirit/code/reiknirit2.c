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

	for (i = j = k = 0; i < n; k++, i = j)                                      // Teljum hversu oft hver tala kemur fyrir.
		for (b[k] = 0; j < n && a[i] == a[j]; j++) b[k]++;





	qsort(b, k, sizeof *b, cmp);                                                // Röðum til að finna algengstu stökin hratt.
	for (i = 0; i < k; i++) r += (i + 1)*b[i];                                  // Leggjum saman hversu oft hver tala er prentuð.
	printf("%lld\n", r);                                                        // Prentum svarið.
	return 0;
}
