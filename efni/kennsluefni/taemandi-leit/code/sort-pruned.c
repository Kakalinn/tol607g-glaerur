#include <stdio.h>
#define SWAP(E, F) { int swap = (E); (E) = (F); (F) = swap; }
int perm(int* a, int n, int x)
{
	int i;
	if (x == n) return 1;                                                       // Allar tölur eru komnar á hlaðann svo hann er raðaður.
	for (i = x; i < n; i++) if (x == 0 || a[x - 1] <= a[i])                     // Ítrum í gegnum allar tölur sem eru eftir og viðhalda röðuðum hlaða.
	{
		SWAP(a[x], a[i]);                                                       // Setjum stak á hlaðann.
		if (perm(a, n, x + 1)) return 1;                                        // Endurkvæmni.
		SWAP(a[x], a[i]);                                                       // Tökum stakið af hlaðanum.
	}
	return 0;
}

int main()
{
	int i, n;
	scanf("%d", &n);                                                            // Innlestur.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	perm(a, n, 0);                                                              // Röðum listanum.
	for (i = 0; i < n; i++) printf("%d ", a[i]);                                // Prentum listann.
	printf("\n");
	return 0;
}
