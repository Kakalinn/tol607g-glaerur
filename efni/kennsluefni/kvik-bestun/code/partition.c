#include <stdio.h>
#include <string.h>
#define MAXN 101
#define MAXC 100001
int max(int a, int b) { if (a < b) return b; return a; }

int d[MAXN][MAXC], b[MAXN];
int dp_lookup(int x, int y)                                                     // Er hægt að skrifa y sem summu talnanna a[0], a[1], ..., a[x].
{
	if (x < 0) return y == 0;                                                   // Við höfum ekki fleiri tölur.
	if (y < 0) return 0;                                                        // Við völdum of stórar tölur samtals.
	if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því.
	return d[x][y] = dp_lookup(x - 1, y) || dp_lookup(x - 1, y - b[x]);         // Prófum bæði að velja x-tu töluna og ekki, og skilum betra svarinu.
}

void partition(int *a, int *r, int n)                                           // Finnur jöfnustu skiptingu talnanna í a.
{
	int i, j, t = 0, c;
	for (i = 0; i < n; i++) t += a[i], r[i] = 0, b[i] = a[i];
	c = t/2;
	for (i = 0; i < n; i++) for (j = 0; j < c + 1; j++) d[i][j] = -1;           // Upphafstillum minnistöfluna.
	while (!dp_lookup(n - 1, c)) c--;                                           // Finnum minnstu tölu minni en t/2 sem er summa talna í a.
	printf(">> %d\n", c);
	for (i = n - 1, j = c; i >= 0 && j > 0; i--)                                // Finnum tölurnar sem gefa okkur summuna c.
		if (dp_lookup(i - 1, j - a[i])) r[i] = 1, j -= a[i];
}

int main()
{
	int n, i, j;
	scanf("%d", &n);                                                            // Innlestur hefst.
	int a[n], r[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	partition(a, r, n);                                                         // Reiknum skiptingarnar.
	printf("Fyrri hópur: ");
	for (i = 0; i < n; i++) if (r[i]) printf(" %2d", a[i]);                     // Prentum fyrri skiptinguna.
	printf("\n");
	printf("Seinni hópur:");
	for (i = 0; i < n; i++) if (!r[i]) printf(" %2d", a[i]);                    // Prentum seinni skiptinguna.
	printf("\n");
	return 0;
}
