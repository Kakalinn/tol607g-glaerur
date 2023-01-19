#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MOD 1000000009
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
{ // reiknar |n|-tu Fibonacci toluna.
	ll n, a[2][2] = {{1, 1}, {1, 0}};
	scanf("%lld", &n);
	if (n == 1 || n == 2) printf("1\n");
	else
	{
		matpow(*a, n - 2, 2);
		printf("%lld\n", (a[0][0] + a[0][1])%MOD);
	}
	return 0;
}
