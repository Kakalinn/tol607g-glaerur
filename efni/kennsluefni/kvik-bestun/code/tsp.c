#include <stdio.h>
#include <assert.h>
#define MAXN 18
#define INF (1 << 30)
int min(int a, int b) { if (a < b) return a; return b; }

int d[MAXN][1 << MAXN], g[MAXN][MAXN], n;
int dp_lookup(int x, int y)
{
	int i;
	if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna svarið. Skilum því.
	if (x == 0 && y != 0) return (y == ((1 << n) - 1)) ? 0 : INF;               // Við erum komin aftur í upphafstöðuna.
	for (d[x][y] = INF, i = 0; i < n; i++) if ((y&(1 << i)) == 0)               // Ítrum í gegnum stöðurnar sem við eigum eftir að heimsækja.
		d[x][y] = min(d[x][y], dp_lookup(i, y + (1 << i)) + g[x][i]);           // Berum saman besta svarið hingað til og ef farið er næst í stöðu i.
	return d[x][y];                                                             // Skilum besta svarinu sem við fundum.
}

int tsp(int *a, int n)                                                          // Finnur stystu rásina sem heimsækir allar stöðurnar.
{
	int i, j;
	for (i = 0; i < n; i++) for (j = 0; j < (1 << n); j++) d[i][j] = -1;        // Upphafstillir minnistöfluna.
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) g[i][j] = a[i*MAXN + j];    // Setur töfluna a í töfluna g.
	return dp_lookup(0, 0);                                                     // Reiknar og skilar svarinu.
}

int main()
{
	int i, j, a[MAXN][MAXN];
	scanf("%d", &n);                                                            // Innlestur hafinn.
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%d", &a[i][j]);      // Innlestri lokið.
	printf("%d\n", tsp(*a, n));                                                 // Reiknar og prentar svarið.
	return 0;
}
