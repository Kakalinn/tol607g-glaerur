#include <stdio.h>
#include <string.h>
#define MAXN 1001
#define MAXC 1001
int max(int a, int b) { if (a < b) return b; return a; }

int d[MAXN][MAXC], b[MAXN];
int dp_lookup(int x, int y)                                                     // Er hægt að skrifa y sem summu talnanna a[0], a[1], ..., a[x]?
{
	if (x < 0) return y == 0;                                                   // Við höfum ekki fleiri tölur.
	if (y < 0) return 0;                                                        // Við völdum of stóra tölu samtals.
	if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því.
	return d[x][y] = dp_lookup(x - 1, y) || dp_lookup(x - 1, y - b[x]);         // Prófum bæði að velja x-tu töluna og ekki, og skilum svarinu.
}

int subsetsum(int *a, int n, int c)                                             // Skilar stærstu tölunni á [0, c] sem má skrifa sem summu talnanna í a.
{
	int i, j;
	for (i = 0; i < n; i++) for (j = 0; j < c + 1; j++) d[i][j] = -1;           // Upphafstillum minnistöfluna.
	for (i = 0; i < n; i++) b[i] = a[i];
	while (!dp_lookup(n - 1, c)) c--;                                           // Finnum stærstu töluna sem má skrifa sem summu talna í a.
	return c;
}

int main()
{
	int n, c, i, j;
	scanf("%d%d", &n, &c);                                                      // Innlestur hefst.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	printf("%d\n", subsetsum(a, n, c));                                         // Reiknum og prentum svarið.
	return 0;
}
