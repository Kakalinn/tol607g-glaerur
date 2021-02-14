#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
typedef long long ll;
ll p[3*MAXN + 1], o[3*MAXN + 1], n;

void prop(ll x, ll y, ll e) //Hjálparfall
{ // Fall sem dreifir lygnum uppfærslum niður um eina hæð.
	p[e] += (y - x + 1)*o[e];   
	if (x != y) o[LEFT(e)] += o[e], o[RIGHT(e)] += o[e];
	o[e] = 0;
}
ll query_rec(ll i, ll j, ll x, ll y, ll e) // Hjálparfall
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) return p[e];
	ll m = (i + j)/2;
	if (x <= m && y <= m) return query_rec(i, m, x, y, LEFT(e));
	else if (x > m && y > m) return query_rec(m + 1, j, x, y, RIGHT(e));
	return query_rec(i, m, x, m, LEFT(e))
			+ query_rec(m + 1, j, m + 1, y, RIGHT(e));
}
ll query(ll x, ll y)
{ // Finnum summuna yfir [x, y].
	return query_rec(0, n - 1, x, y, 1);
}
void update_rec(ll i, ll j, ll x, ll y, ll z, ll e) // Hjálparfall
{ // Við erum að leita að bili [x, y] og erum í [i, j].
	prop(i, j, e);
	if (x == i && y == j) { o[e] = z; return; }
	ll m = (i + j)/2;
	p[e] += (y - x + 1)*z;
	if (x <= m && y <= m) update_rec(i, m, x, y, z, LEFT(e));
	else if (x > m && y > m) update_rec(m + 1, j, x, y, z, RIGHT(e));
	else update_rec(i, m, x, m, z, LEFT(e)),
		   update_rec(m + 1, j, m + 1, y, z, RIGHT(e));
}
void update(ll x, ll y, ll z)
{ // Bætum z við stökin á bilinu [x, y]
	update_rec(0, n - 1, x, y, z, 1);
}

ll slow(ll* a, ll l, ll r)
{
	ll x = 0;
	while (l <= r) x += a[l++];
	return x;
}

ll get_int()
{
	ll ret = 0;
	char c = getchar();
	ll sgn;

	while (1)
	{
		if (c == EOF) return EOF;
		if (c >= '0' && c <= '9') { sgn = 1; break; }
		if (c == '-')
		{
			c = getchar();
			if (c < '0' || c > '9') continue;
			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';
		c = getchar();
		if (c < '0' || c > '9') return sgn*ret;
	}
}

int main()
{
	srand(time(NULL));
	n = get_int();
	ll i, j, q = get_int(), x, w, y;
	for (i = 0; i < 3*n + 1; i++) p[i] = o[i] = 0;
	while (q-- != 0)
	{
		char c = getchar();
		if (c == '+')
		{
			ll x = get_int(), y = get_int();
			update(x, x, y);
		}
		else
		{
			ll x = get_int() - 1;
			printf("%lld\n", x == -1 ? 0 : query(0, x));
		}
	}
	return 0;
}
