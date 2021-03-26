#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MOD 1000000007
typedef long long ll;

void multo(ll* a, ll* b, ll n)
{ // Eins og `a *= b`.
	int i, j, k, c[n][n];
	rep(i, n) rep(j, n) c[i][j] = 0;
	rep(i, n) rep(j, n) rep(k, n) c[i][j] = (c[i][j] + (a[i*n + k]*b[k*n + j])%MOD)%MOD;
	rep(i, n) rep(j, n) a[i*n + j] = c[i][j];
}

void matpow(ll* a, ll p, ll n)
{ // Eins og a = a^p.
	ll r[n][n], i, j;
	rep(i, n) rep(j, n) r[i][j] = 0;
	rep(i, n) r[i][i] = 1;
	while (p > 0)
	{
		if (p%2 == 1) multo(*r, a, n);
		p /= 2;
		multo(a, a, n);
	}
	rep(i, n) rep(j, n) a[i*n + j] = r[i][j];
}

int main()
{ // reiknar |n|-ta Fibonacci toluna.
	ll i, j, n, r = 0, a[8][8] =
	{
		{1, 1, 1, 0, 1, 1, 0, 0},
		{1, 0, 1, 0, 1, 0, 0, 0},
		{1, 1, 0, 0, 1, 1, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{1, 1, 1, 0, 0, 0, 0, 0},
		{1, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
	};
	scanf("%lld", &n);
	matpow(*a, n - 1, 8);
	rep(i, 8) rep(j, 8) if (i != 3 && i != 6 && i != 7) r = (r + a[i][j])%MOD;
	printf("%lld\n", r);
	return 0;
}
