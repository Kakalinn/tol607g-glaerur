#include <stdio.h>
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int main()                                                                      // Skiptimyntadæmið án endurtekningar.
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
	int d[n + 1], a[m];
	for (i = 0; i < m; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	for (i = 0; i < n + 1; i++) d[i] = INF;                                     // Upphafstillum minnistöfluna.
	d[0] = 0;
	for (i = 0; i < m; i++)                                                     // Ítrum í gegnum klinkið.
		for (j = n - a[i]; j >= 0; j--) if (d[j] < INF)                         // Ítrum afturábak í gegnum minnistöfluna.
			d[j + a[i]] = min(d[j + a[i]], d[j] + 1);                           // Uppfærum ef það þarf.
	printf("%d\n", d[n]);                                                       // Prentum svarið.
	return 0;
}
