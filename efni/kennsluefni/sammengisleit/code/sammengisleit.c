#include <stdio.h>
#define MAXN 1000000

int find(int *p, int x)                                                         // Finnur ráðherra flokksins sem x tilheyrir.
{
    return p[x] < 0 ? x : (p[x] = find(p, p[x]));                               // Skilar ráðherranum ef hann er fundinn. Þjappar annars keðjuna.
}

void join(int *p, int x, int y)                                                 // Sameinar flokkana sem x og y tilheyra.
{
    int rx = find(p, x), ry = find(p, y);                                       // Finnum ráðherra hvors flokks.
    if (rx == ry) return;                                                       // Ef x og y eru í sama flokknum þarf ekkert að gera.
    if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;                              // Ef keðjan undir rx inniheldur færri stök verður rx nýi ráðherrann.
    else p[rx] += p[ry], p[ry] = rx;                                            // Ef keðjan undir ry inniheldur færri stök verður ry nýi ráðherrann.
}

void init(int *p, int n)                                                        // Upphafstillir keðjurnar sem eru minni en n.
{
    for (int i = 0; i < n; i++) p[i] = -1;
}

int size(int *p, int x)                                                        // Skilar fjölda staka í sama flokki og x.
{
    return -p[find(p, x)];
}

int main()
{
    int i, n = MAXN;
    int p[n];
    init(p, n);
    //...
    return 0;
}
