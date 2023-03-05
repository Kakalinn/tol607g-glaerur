#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
#define LEFT(x) ((x) + 1)
#define RIGHT(x, m, i) ((x) + 2*(m - i + 1))
int p[2*MAXN], o[2*MAXN];

void prop(int x, int y, int e)                                                  // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
{
	p[e] += (y - x + 1)*o[e];   
	if (x != y) o[LEFT(e)] += o[e], o[RIGHT(e, (x + y)/2, x)] += o[e];
	o[e] = 0;
}

int qrec(int i, int j, int x, int y, int e)                                     // Við erum að leita að bili [x, y] og erum í [i, j].
{
	prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
	if (x == i && y == j) return p[e];                                          // Við fundum akkúrat bilið.
	int m = (i + j)/2;                                                          // Finnum miðju bilsins sem við erum að leita í.
	if (y <= m) return qrec(i, m, x, y, LEFT(e));                               // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e, m, i));                // Bilið sem við erum að leita að er hægra megin við miðjuna.
	return qrec(i, m, x, m, LEFT(e))
			+ qrec(m + 1, j, m + 1, y, RIGHT(e, m, i));                         // Miðjan skiptir bilinu í tvennt.
}
int query(int x, int y)                                                         // Finnum summuna yfir [x, y].
{
	return qrec(0, p[0] - 1, x, y, 1);
}

void urec(int i, int j, int x, int y, int z, int e)                             // Við erum að leita að bili [x, y] og erum í [i, j].
{
	prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
	if (x == i && y == j) { o[e] = z; return; }                                 // Við fundum akkúrat bilið.
	int m = (i + j)/2;                                                          // Finnum miðju bilsins sem við erum að leita í.
	p[e] += (y - x + 1)*z;                                                      // Uppfærum gildið sem tréð geymir.
	if (y <= m) urec(i, m, x, y, z, LEFT(e));                                   // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	else if (x > m) urec(m + 1, j, x, y, z, RIGHT(e, m, i));                    // Bilið sem við erum að leita að er hægra megin við miðjuna.
	else urec(i, m, x, m, z, LEFT(e)),
			urec(m + 1, j, m + 1, y, z, RIGHT(e, m, i));                        // Miðjan skiptir bilinu í tvennt.
}
void update(int x, int y, int z)                                                // Bætum z við stökin á bilinu [x, y]
{
	urec(0, p[0] - 1, x, y, z, 1);
}

void init(int n)                                                                // Upphafstillum tréð. Fylkin o og p þurfa að rúma 5*n stök!
{
	for (int i = 0; i < 2*n; i++) p[i] = o[i] = 0;
	p[0] = n;                                                                   // Til þæginda geymum við stærðina í stakinu sem er ekki notað í trénu.
}

int slow(int* a, int l, int r)
{
	int x = 0;
	while (l <= r) x += a[l++];
	return x;
}

int main()
{
	srand(time(NULL));
	int i, j, x, y, z, w, n = 400, q = 400;
	int a[n];
	for (i = 0; i < n; i++) a[i] = 0;
	init(n);
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + rand()%(n - x), y = rand()%(n*10);
		update(x, w, y);
		for (i = x; i <= w; i++) a[i] += y;
		for (i = 0; i < n; i++) for (j = i; j < n; j++) assert(query(i, j) == slow(a, i, j));
	}
	return 0;
}
