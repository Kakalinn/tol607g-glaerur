#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
typedef long long ll;
ll p[MAXN], o[MAXN], n;

// hjálparfall sem hrindir gildinu o_e fram á börnin.
void prop(ll x, ll y, ll e)
{
	p[e] += (y - x + 1)*o[e];
	if (x != y) o[LEFT(e)] += o[e], o[RIGHT(e)] += o[e];
	o[e] = 0;
}

// við erum í nóðunni sem svarar til [i, j] og erum að leita að [x, y].
// Við notum e sem vísi í hrúgu.
ll query_(ll i, ll j, ll x, ll y, ll e)
{
	prop(i, j, e);
	if (x == i && y == j) return p[e];
	ll m = (i + j)/2;
	if (x <= m && y <= m) return query_(i, m, x, y, LEFT(e));
	else if (x > m && y > m) return query_(m + 1, j, x, y, RIGHT(e));
	return query_(i, m, x, m, LEFT(e)) + query_(m + 1, j, m + 1, y, RIGHT(e));
}
// reiknar summuna a_x + a_{x + 1} + ... + a_{y - 1} + a_y.
ll query(ll x, ll y)
{
	return query_(0, n - 1, x, y, 1);
}

// við erum í nóðunni sem svarar til [i, j] og erum að leita að [x, y].
// Við notum e sem vísi í hrúgu.
void update_(ll i, ll j, ll x, ll y, ll z, ll e)
{
	prop(i, j, e);
	if (x == i && y == j) { o[e] = z; return; }
	ll m = (i + j)/2;
	p[e] += (y - x + 1)*z;
	if (x <= m && y <= m) update_(i, m, x, y, z, LEFT(e));
	else if (x > m && y > m) update_(m + 1, j, x, y, z, RIGHT(e));
	else update_(i, m, x, m, z, LEFT(e)), update_(m + 1, j, m + 1, y, z, RIGHT(e));
}
// bætir z við tölurnar a_x, a_{x + 1}, ..., a_{y - 1}, a_y.
void update(ll x, ll y, ll z)
{
	update_(0, n - 1, x, y, z, 1);
}

int main()
{
	srand(time(NULL));
	ll i, q = 100000, x, w, y, z;
	n = 100000;
	for (i = 0; i < 5*n; i++) p[i] = o[i] = 0;
	while (q-- != 0)
	{
		x = rand()%(n - 1), w = x + rand()%(n - x), y = rand()%(n*10), z = rand()%2;
		if (z) update(x, w, y);
		else printf("%d\n", query(x, w));
	}
	return 0;
}
