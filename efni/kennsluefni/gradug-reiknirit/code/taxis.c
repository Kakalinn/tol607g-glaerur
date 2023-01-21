#include <stdio.h>

int main()
{
	int n, m, i, j, x, r;
	scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
	int a[n], b[m];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < m; i++) scanf("%d", &b[i]);                                 // Innlestri lokið.
	for (i = r = j = 0; i < m; i++)                                             // Ítrum í gegnum bílana.
	{
		while (j < n && a[j] < b[i]) j++;                                       // Finnum óhæfasta bílstjórann sem ræður við tiltekinn bíl.
		if (j < n) r++, j++;                                                    // Skipum bílstjóra á bíl.
	}
	printf("%d\n", r);                                                          // Prentum svarið.
	return 0;
}
