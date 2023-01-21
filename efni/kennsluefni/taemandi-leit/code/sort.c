#include <stdio.h>
#define SWAP(E, F) { int swap = (E); (E) = (F); (F) = swap; }
int perm(int* a, int n, int x)
{
	int i;
	if (x == n)                                                                 // Við förum hér ef allar tölurnar eru komnar á hlaðann.
	{
		for (i = 0; i < n - 1; i++) if (a[i] > a[i + 1]) break;                 // Skoðum hvort tiltekin umröðun sé vaxandi.
		return i < n - 1 ? 0 : 1;
	}
	for (i = x; i < n; i++)                                                     // Ítrum í gegnum tölurnar sem eru eftir.
	{
		SWAP(a[x], a[i]);                                                       // Setjum stak á hlaðann sem er ekki á honum.
		if (perm(a, n, x + 1)) return 1;                                        // Endurkvæmni.
		SWAP(a[x], a[i]);                                                       // Tökum stakið aftur af hlaðanum.
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
