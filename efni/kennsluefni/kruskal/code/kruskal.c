#include <stdio.h>                                                              // Fyrsta lína inntaksins eru tvær heiltölur,
#include <stdlib.h>                                                             // Síðan koma m línur sem svara til leggjalistans.
typedef struct { int x, y, z; } ii;                                             //   fjöldi hnúta og fjöldi leggja.
int cmp(const void* p1, const void* p2) { return ((ii*)p1)->z - ((ii*)p2)->z; }

int uf_find(int *p, int x)                                                      // Finnur ráðherra flokksins sem x tilheyrir.
{
	return p[x] < 0 ? x : (p[x] = uf_find(p, p[x]));                            // Skilar ráðherranum ef hann er fundinn. Þjappar annars keðjuna.
}

void uf_join(int *p, int x, int y)                                              // Sameinar flokkana sem x og y tilheyra.
{
	int rx = uf_find(p, x), ry = uf_find(p, y);                                 // Finnum ráðherra hvors flokks.
	if (rx == ry) return;                                                       // Ef x og y eru í sama flokknum þarf ekkert að gera.
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;                              // Ef keðjan undir rx inniheldur færri stök verður rx nýi ráðherrann.
	else p[rx] += p[ry], p[ry] = rx;                                            // Ef keðjan undir ry inniheldur færri stök verður ry nýi ráðherrann.
}

void uf_init(int *p, int n)                                                     // Upphafstillir keðjurnar sem eru minni en n.
{
	for (int i = 0; i < n; i++) p[i] = -1;
}

int kruskal(ii* e, ii* t, int n, int m)
{
	int i, j = 0, r = 0, p[n];
	uf_init(p, n);                                                              // Upphafstillum sammengisleitina.
	qsort(e, m, sizeof(e[0]), cmp);                                             // Röðum leggjunum í vaxandi þyngdarröð.
	for (i = 0; i < m; i++)
	{
		if (uf_find(p, e[i].x) == uf_find(p, e[i].y)) continue;                 // Ítrum í gegnum alla leggina sem mynda ekki rás.
		r += e[i].z;                                                            // Bætum leggnum við. Við uppfærum heildarstærðina á spannandi trénu.
		uf_join(p, e[i].x, e[i].y);                                             // Sameinum samhengisþættina.
		t[j++] = e[i];                                                          // Bætum leggnum í tréð.
	}
	return r;                                                                   // Skilum stærðinni á minnsta spannandi trénu.
}

int main()
{
	int n, m, x, y, z, i;
	scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
	ii a[m], t[n - 1];
	for (i = 0; i < m; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
	for (i = 0; i < m; i++) a[i].x--, a[i].y--;                                 // Innlestri lokið.
	printf("Stærðin á minnsta spannandi trénu er %d.\n", kruskal(a, t, n, m));
	printf("Eftirfarandi leggir eru í minnsta spannandi tré netsins:\n");
	for (i = 0; i < n - 1; i++) printf("  (%d, %d)\n", t[i].x, t[i].y);
	return 0;
}
