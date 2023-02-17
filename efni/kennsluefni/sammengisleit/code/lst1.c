#include <stdio.h>
#define MAXN 10000

int p[MAXN];
int find(int x)                                                                 // Finnur ráðherra flokksins sem x tilheyrir.
{
	if (p[x] == x) return x;                                                    // Ef p[x] == x þá er x ráðherrann.
	return find(p[x]);                                                          // Leitum upp keðjuna.
}

void join(int x, int y)                                                         // Sameinar flokkana sem x og y tilheyra.
{
	p[find(x)] = find(y);                                                       // Ráðherra flokksins sem x tilheyrir er nú ráðherra beggja flokkanna.
}

void init(int n)                                                                // Upphafstillir keðjurnar sem eru minni en n.
{
	for (int i = 0; i < n; i++) p[i] = i;
}

int main()
{
	int i, n = MAXN;
	init(n);
	//...
	return 0;
}
