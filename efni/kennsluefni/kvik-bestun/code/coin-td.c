#include <stdio.h>
#define MAXN 10001
#define MAXM 10001
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int n, m, a[MAXM];
int d[MAXN];
int dp_lookup(int x)                                                            // Minnsta klink sem þarf til að gefa til baka x.
{
	int i;
	if (x < 0) return INF;                                                      // Við gáfum of mikið klink til baka. Þessi lína þarf að vera fremst!
	if (d[x] != -1) return d[x];                                                // Við erum búin að reikna svarið. Skilum því.
	if (x == 0) return 0;                                                       // Grunntilfelli.
	d[x] = INF;
	for (i = 0; i < m; i++) d[x] = min(d[x], dp_lookup(x - a[i]) + 1);          // Prófum að gefa allt klink til baka.
	return d[x];                                                                // Skilum því besta sem við fundum.
}

int main()                                                                      // Skiptimyntadæmið með endurtekningu.
{
	int i;
	scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
	for (i = 0; i < m; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	for (i = 0; i < n + 1; i++) d[i] = -1;                                      // Upphafstillum minnistöfluna.
	printf("%d\n", dp_lookup(n));                                               // Reiknum og prentum svarið.
	return 0;
}
