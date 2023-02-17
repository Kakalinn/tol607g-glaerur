#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int p[MAXN*5];
int max(int a, int b) { return a > b ? a : b; }

int qrec(int i, int j, int x, int y, int e)                                     // Við erum að leita að bili [x, y] og erum í [i, j].
{
	if (x == i && y == j) return p[e];                                          // Við fundum akkúrat bilið.
	int m = (i + j)/2;                                                          // Finnum miðju bilsins sem við erum að leita í.
	if (y <= m) return qrec(i, m, x, y, LEFT(e));                               // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));                           // Bilið sem við erum að leita að er hægra megin við miðjuna.
	return max(qrec(i, m, x, m, LEFT(e)), qrec(m + 1, j, m + 1, y, RIGHT(e)));  // Miðjan skiptir bilinu í tvennt.
}
int query(int x, int y)                                                         // Finnum stærsta gildið á [x, y].
{
	return qrec(0, p[0] - 1, x, y, 1);
}

void urec(int i, int j, int x, int y, int e)                                    // Við erum að leita að laufinu [x, x] og erum í [i, j].
{
	if (i == j) p[e] = y;                                                       // Við erum komin í lauf.
	else
	{
		int m = (i + j)/2;                                                      // Finnum miðjuna á bilinu sem við erum í.
		if (x <= m) urec(i, m, x, y, LEFT(e));                                  // Laufið sem við leitum að er vinstra megin við miðjuna.
		else urec(m + 1, j, x, y, RIGHT(e));                                    // Laufið sem við leitum að er hægra megin við miðjuna.
		p[e] = max(p[LEFT(e)], p[RIGHT(e)]);                                    // Lögum summun sem er geymd í hnútnum sem við erum í.
	}
}
void update(int x, int y)                                                       // Látum x-ta stakið vera y.
{
	return urec(0, p[0] - 1, x, y, 1);
}

void init(int n)                                                                // Upphastillum tréð. Fylkið p þarf að rúma 5*n stök!
{
	for (int i = 0; i < 5*n; i++) p[i] = 0;
	p[0] = n;                                                                   // Til þæginda geymym við stærðina í stakinu sem er ekki notað í trénu.
}

int slow(int* a, int x, int y)                                                  // Línuleg útfærsla til að bera saman.
{
	int r = -(1 << 30);
	while (x <= y) r = max(r, a[x++]);
	return r;
}

// Þetta forrit prófar max-range-query, point-assigment-update á slembnar uppfærlsur.
// Eftir hverja uppfærslu eru allar mögulegar fyrirspurnir framkvæmdar.
// Svo forritið er hægt, nánar O(n^3).
int main()
{
	srand(time(NULL));
	int i, j, x, y, z, n = 400, q = 400, m = 100;
	int a[n];
	for (i = 0; i < n; i++) a[i] = 0;
	init(n);
	while (q-- != 0)
	{
		x = rand()%n, y = x + rand()%(n - x), z = rand()%(2*m + 1) - m;
		update(x, z), a[x] = z;
		for (i = 0; i < n; i++) for (j = i; j < n; j++) assert(query(i, j) == slow(a, i, j));
	}
	return 0;
}
