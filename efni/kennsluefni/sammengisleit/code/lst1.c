#include <stdio.h>
#define MAXN 10000

int find(int *p, int x)                                                         // Finnur ráðherra flokksins sem x tilheyrir.
{
    if (p[x] == x) return x;                                                    // Ef p[x] == x þá er x ráðherrann.
    return find(p, p[x]);                                                       // Leitum upp keðjuna.
}

void join(int *p, int x, int y)                                                 // Sameinar flokkana sem x og y tilheyra.
{
    p[find(p, x)] = find(p, y);                                                 // Ráðherra flokksins sem x tilheyrir er nú ráðherra beggja flokkanna.
}

void init(int *p, int n)                                                        // Upphafstillir keðjurnar sem eru minni en n.
{
    for (int i = 0; i < n; i++) p[i] = i;
}

int main()
{
    int i, n = MAXN;
    int p[n];
    init(p, n);
    //...
    return 0;
}
