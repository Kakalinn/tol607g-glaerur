#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);                                                            // Les inn fjölda talna.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));                               // Les inn tölurnar.

	int mx = 0, mask;
	for (i = 0; i < (1 << n); i++)                                              // Ítra í gegnum alla bitakenna.
	{
		int s[n], c = 0;
		for (j = 0; j < n; j++) if (((1 << j)&i) != 0) s[c++] = j;              // Finnum hlutrununa sem svara til tiltekins bitakennis.
		for (j = 1; j < c; j++) if (a[s[j]] < a[s[j - 1]]) break;               // Skoðum hvort hlutrunan sé vaxandi.
		if (j == c && c > mx) mx = c, mask = i;                                 // Uppfærum bestu niðurstöðuna hingað til ef nauðsyn er.
	}

	printf("%d\n", mx);                                                         // Prentum svarið.
	for (i = 0; i < n; i++) if (((1 << i)&mask) != 0) printf("%d ", a[i]);
	printf("\n");

	return 0;
}
