#include <stdlib.h>
#include <stdio.h>
typedef long long ll;

#define CMP(E, F) (F <= E) - (E <= F)
int cmp(const void* p1, const void* p2)
{
	return CMP(*(ll*)p2, *(ll*)p1);
}

int main()
{
	ll i, j, k, r = 0, n;
	scanf("%lld", &n);
	ll a[n], b[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);
	qsort(a, n, sizeof *a, cmp);
	i = k = 0;
	while (i < n)
	{ // teljum hvað hver tala kemur oft fyrir.
		j = i;
		while (j < n && a[i] == a[j]) j++;
		b[k++] = j - i;
		i = j;
	}
	qsort(b, k, sizeof *b, cmp);
	for (i = 0; i < k; i++) r = r + (i + 1)*b[i];
	printf("%lld\n", r);
	return 0;
}
