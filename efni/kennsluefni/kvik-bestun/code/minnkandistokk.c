#include <stdio.h>
#include <assert.h>
typedef long long ll;
#define MAXN 3001
#define INF (1LL << 60)
ll max(ll a, ll b) { return a > b ? a : b; }
ll min(ll a, ll b) { return a < b ? a : b; }

int main()
{
	ll i, j, k, n;
	scanf("%lld", &n);                                                          // Innlestur hefst.
	ll d[n][n], e[n], a[n];
	for (i = 0; i < n; i++) scanf("%lld", &a[i]);                               // Innlestri lokið.
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) d[i][j] = -INF;             // Upphafstillum minnistöfluna.
	d[n - 1][1] = e[n - 1] = a[n - 1];
	for (i = n - 2; i >= 0; i--) e[i] = d[i][1] = d[i + 1][1] + a[i];           // Tökum alltaf eitt stökk.
	for (j = 2; j < n; j++)                                                     // Ítrum í vaxandi stökk röð.
	{
		e[n - j] = max(e[n - j], d[n - 1][j] = a[n - 1]);
		for (i = n - 2; i >= 0; i--)                                            // Ítrum í minnkandi stöðum.
		{
			d[i][j] = e[i + 1] + a[i];                                          // Reiknum d[i][j] með því að skoða skálínuna.
			if (i >= j - 1) e[i - j + 1] = max(e[i - j + 1], d[i][j]);          // Uppfærum skálínu stakið ef það á við.
		}
	}
	printf("%lld\n", d[0][n - 1]);                                              // Prentum svarið.
	return 0;
}
