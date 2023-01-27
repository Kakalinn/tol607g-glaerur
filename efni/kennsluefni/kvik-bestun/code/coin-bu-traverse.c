#include <stdio.h>
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int main()
{
	int i, j, n, m, x;
	scanf("%d%d", &n, &m);                                                      // Innlestur hafinn.
	int d[n + 1], a[m], e[n + 1];
	for (i = 0; i < m; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	for (i = 0; i < n + 1; i++) d[i] = INF;                                     // Upphafstillum minnistöfluna.
	d[0] = 0;
	for (i = 0; i < m; i++)                                                     // Ítrum í gegnum klinkið.
		for (j = 0; j < n + 1 - a[i]; j++)                                      // Ítrum í gegnum minnistöfluna.
			if (d[j] < INF && d[j + a[i]] > d[j] + 1)                           // Athugum hvort það þurfi að uppfæra.
	{
		d[j + a[i]] = d[j] + 1;                                                 // Uppfærum besta svarið.
		e[j + a[i]] = a[i];                                                     // Uppfærum hvaða klink gaf okkur þetta besta svar.
	}

	printf("%d\n", d[n]);                                                       // Prentum besta svarið.
	x = n;
	while (x != 0)                                                              // Ítrum í gegnum klinkið sem gaf okkur besta svarið.k
	{
		printf("%d ", e[x]);                                                    // Prentum tiltekið klink sem gaf okkur besta svarið.
		x -= e[x];
	}
	printf("\n");
	return 0;
}
