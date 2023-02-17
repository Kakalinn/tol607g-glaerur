#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 1000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
typedef long long ll;
ll min(ll a, ll b) { return a < b ? a : b; }
ll max(ll a, ll b) { return a > b ? a : b; }

typedef struct { ll v, o, m; } node;
node p[5*MAXN];

void prop(ll x, ll y, ll e)                                                     // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
{
	p[e].m += p[e].o;                                                           // Uppfærum gildið í hnútnum.
	if (x != y) p[RIGHT(e)].o += p[e].o, p[LEFT(e)].o += p[e].o;                // Skiptum lygnu uppfærslunni í tvennt.
	p[e].o = 0;
}

ll qrecm(ll i, ll j, ll x, ll y, ll e)                                          // Við erum að leita að bili [x, y] og erum í [i, j].
{
	prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
	if (x == i && y == j) return p[e].m;                                        // Við fundum akkúrat bilið.
	ll m = (i + j)/2;                                                           // Finnum miðju bilsins sem við erum að leita í.
	if (y <= m) return qrecm(i, m, x, y, LEFT(e));                              // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	else if (x > m) return qrecm(m + 1, j, x, y, RIGHT(e));                     // Bilið sem við erum að leita að er hægra megin við miðjuna.
	return min(qrecm(i, m, x, m, LEFT(e)),
			qrecm(m + 1, j, m + 1, y, RIGHT(e)));                               // Miðjan skiptir bilinu í tvennt.
}
ll querymin(ll x, ll y)                                                         // Finnum minnsta gilið á [x, y].
{
	return qrecm(0, p[0].v - 1, x, y, 1);
}

ll qrec(ll i, ll j, ll x, ll y, ll e)                                           // Við erum að leita að bili [x, y] og erum í [i, j].
{
	prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
	if (x == i && y == j) return p[e].v;                                        // Við fundum akkúrat bilið.
	ll m = (i + j)/2, v1, v2, w1, w2;                                           // Finnum miðju bilsins sem við erum að leita í.
	if (y <= m) return qrec(i, m, x, y, LEFT(e));                               // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));                      // Bilið sem við erum að leita að er hægra megin við miðjuna.
	v1 = qrec(i, m, x, m, LEFT(e)), v2 = qrec(m + 1, j, m + 1, y, RIGHT(e));    // Miðjan skiptir bilinu í tvennt.
	w1 = qrecm(i, m, x, m, LEFT(e)), w2 = qrecm(m + 1, j, m + 1, y, RIGHT(e));  // Finnum minnstu tölun og fjöldann fyrir hvorn helming.
	return (w1 <= w2)*v1 + (w1 >= w2)*v2;                                       // Púslum saman og skilum réttu svari.
}
ll query(ll x, ll y)                                                            // Finnum ... yfir [x, y].
{
	if (y < x) return 0;                                                        // Tómt bil.
	ll z = qrec(0, p[0].v - 1, x, y, 1);                                        // Finnum fjölda minnstu staka á bilinu.
	return querymin(x, y) == 0 ? z : 0;                                         // Ef núll er ekki minnsta talan á bilinu er svarið núll.
}

void urec(ll i, ll j, ll x, ll y, ll z, ll e)                                   // Við erum að leita að bili [x, y] og erum í [i, j].
{
	prop(i, j, e);                                                              // Pössum að það sé ekki lygn uppfærsla í hnútnum sem við erum í.
	if (x == i && y == j) { p[e].o = z; return; }                               // Við fundum akkúrat bilið.
	ll m = (i + j)/2, v1, v2;                                                   // Finnum miðju bilsins sem við erum að leita í.
	if (y <= m) urec(i, m, x, y, z, LEFT(e));                                   // Bilið sem við erum að leita að er vinstra megin við miðjuna.
	else if (x > m) urec(m + 1, j, x, y, z, RIGHT(e));                          // Bilið sem við erum að leita að er hægra megin við miðjuna.
	else urec(i, m, x, m, z, LEFT(e)), urec(m + 1, j, m + 1, y, z, RIGHT(e));   // Miðjan skiptir bilinu í tvennt.
	v1 = p[LEFT(e)].m + p[LEFT(e)].o, v2 = p[RIGHT(e)].m + p[RIGHT(e)].o;       // Finnum minnstu gildi barnanna.
	p[e].m = min(v1, v2);                                                       // Uppfærum minnsta gildið í trénu.
	p[e].v = (v1 <= v2)*p[LEFT(e)].v + (v1 >= v2)*p[RIGHT(e)].v;                // Uppfærum fjölda minnstu gildanna.
}
void update(ll x, ll y, ll z)                                                   // Bætum z við stökin á bilinu [x, y].
{
	urec(0, p[0].v - 1, x, y, z, 1);
}

void irec(ll i, ll j, ll e, ll *a)                                              // Við erum að upphafstilla hnútinn sem svara til bilsins [i, j].
{
	p[e].v = p[e].o = p[e].m = 0;                                               // Upphafstillum allt tómt.
	if (i == j) { p[e].v = a[i + 1] - a[i]; return; }                           // Upphafstillum rétt gildi í laufið.
	ll m = (i + j)/2;                                                           // Finnum miðjuna á bilin sem við erum í.
	irec(i, m, LEFT(e), a), irec(m + 1, j, RIGHT(e), a);                        // Förum endurkvæmt í bæði hægra og vinstra barn.
	p[e].v = p[LEFT(e)].v + p[RIGHT(e)].v;                                      // Reiknum rétta summu (því öll gildinu eru 0).
}
void init(ll *a, ll n)                                                          // Upphafstillum tréð. Fylkið p þarf að rúma 5*n stök!
{
	irec(0, (p[0].v = n) - 1, 1, a);                                            // Til þæginda geymum við stærðina í stakinu sem er ekki notað í trénu.
}

ll slow(ll* a, ll *b, ll l, ll r)
{
	ll x = 0;
	while (l < r)
	{
		if (a[l] == 0) x += b[l];
		l++;
	}
	return x;
}

int main()
{
	srand(time(NULL));
	ll i, j, k, x, z, w, n = 20, q = 100000, m = 40;
	ll a[m], v[20] = {3, 5, 6, 7, 8, 11, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 39}, g[20];
	assert(20 == n);
	for (i = 0; i < n; i++) a[i] = 0;
	for (i = 1; i < n - 1; i++) g[i] = v[i + 1] - v[i];
	g[n - 1] = 0;
	init(v, n - 1);
	for (i = 0; i < n; i++) printf("%3d ", i); printf("\n");
	for (i = 0; i < n; i++) printf("%3d ", v[i]); printf("\n");
	for (i = 0; i < n; i++) printf("%3d ", g[i]); printf("\n");
	for (i = 0; i < n - 1; i++) printf("%3d ", query(i, i)); printf("\n");
	for (i = 0; i < n - 1; i++) printf("%3d ", querymin(i, i)); printf("\n");
	while (q-- != 0)
	{
		x = rand()%(n - 2), w = x + rand()%(n - x - 1), z = rand()%100 - 50;
		z = max(z, -querymin(x, w));
		if (rand()%10) z = -querymin(x, w);
		update(x, w, z);
		for (i = x; i <= w; i++) a[i] += z;
		for (i = 0; i < n; i++) assert(a[i] >= 0);
		for (i = 0; i < n - 1; i++) { for (j = i; j < n - 1; j++) if (query(i, j - 1) != slow(a, g, i, j)) break; if (j < n - 1) break; }
		if (i < n - 1)
		{
			printf(">> min %d\n", querymin(i, j));
			printf(">> i, j = %d %d\n", i, j);
			printf(">> v[i], v[j] = %d %d\n", v[i], v[j]);
			printf(">> >> q, s = %d %d\n", query(i, j - 1), slow(a, g, i, j));
			assert(0);
		}
	}
	for (i = 0; i < n - 1; i++) for (j = i; j < n - 1; j++) printf(">> %d %d : %d\n", i, j, query(i, j));
	printf("...\n");
	printf("inds: "); for (i = 0; i < n; i++) printf("%3d ", i); printf("\n");
	printf("g:    "); for (i = 0; i < n; i++) printf("%3d ", g[i]); printf("\n");
	printf("q:    "); for (i = 0; i < n - 1; i++) printf("%3d ", query(i, i)); printf("\n");
	printf("qmn:  "); for (i = 0; i < n - 1; i++) printf("%3d ", querymin(i, i)); printf("\n");
	printf("a:    "); for (i = 0; i < n; i++) printf("%3d ", a[i]); printf("\n");
	return 0;
}
