#include <stdio.h>                                                              // Fyrsta lína inntaksins eru tvær heiltölur,
                                                                                //   fjöldi hnúta og fjöldi leggja.
                                                                                // Síðan koma m línur sem svara til leggjalistans.

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

int main()
{
	int i, j, n, m, c = 0, x , y;
	scanf("%d%d", &n, &m);                                                      // Lesum inn fjölda hnúta og fjölda leggja.
	int p[n], v[n];
	uf_init(p, n);                                                              // Upphafstillum sammengisleitina.
	for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
	{
		scanf("%d%d", &x, &y);                                                  // Tiltekinn leggur er frá hnút x til hnúts y.
		x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
		uf_join(p, x, y);                                                       // Sameinum samhengisþætti x og y, ef þörf er á.
	}
	for (i = 0; i < n; i++) v[i] = 0;                                           // Við þurfum að finna oddvitana til að vita hversu margir
	for (i = 0; i < n; i++) v[uf_find(p, i)] = 1;                               //   samhengisþættirnir eru.

	printf("Fjöldi samhengisþátta er %d.\n", c);
	for (i = 0; i < n; i++)
		printf("Hnútur %d er í samhengisþætti %d.\n", i + 1, uf_find(p, i));
	return 0;
}
