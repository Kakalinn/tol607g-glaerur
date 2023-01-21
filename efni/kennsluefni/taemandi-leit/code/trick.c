#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <assert.h>
#define MAXN 30
#define MAXM 10000

int cmp(const void* p1, const void* p2)                                         // Hefðbundið samanburðarfall.
{
	int x = *(int*)p1, y = *(int*)p2;
	return (y <= x) - (x <= y);
}

void bf(int *a, int n, int *u)                                                  // Reiknum summur allra hlutmengja í listan a.
{
	int i, j;
	for (i = 0; i < (1 << n); i++)                                              // Ítrum í gegnum alla bitakenna.
	{
		u[i] = 0;                                                               // Upphafstillum summu hlutmengisins sem svara til tiltekins bitakennis.
		for (j = 0; j < n; j++) if (i&(1 << j)) u[i] += a[j];                   // Reiknum summu allra stakanna sem eru í hlutmenginu.
	}
}

int bs(int *a, int t, int n)                                                    // Finnur fremst staðinn sem t gæti verið í röðuðu a með helmingunarleit.
{
	int r = -1, s;
	for (s = n; s >= 1; s /= 2) while (r + s < n && a[r + s] < t) r += s;
	return r + 1;
}

int count(int x)                                                                // Reiknar hversu margir ásar eru í bitaframsetningu x.
{
	return __builtin_popcount(x);
}

int solve(int *a, int *b, int n, int m, int x, int t)                           // Leysum eftir skiptingu, a er fyrri skiptingin og b sú seinni.
{
	int r = 0, i, j, z, u[1 << n], v[1 << m], e, l[m + 1], h[m + 1][1 << m];
	for (i = 0; i < m + 1; i++) l[i] = 0;
	bf(a, n, u), bf(b, m, v);                                                   // Reiknum summu allra hlutmengja hvorrar skiptingar.
	for (i = z = 0; i < 1 << m; z = count(++i)) h[z][l[z]++] = v[i];            // Ítrum í gegnum seinni skiptinguna og flokkum hlutmengin eftir stærðum.
	for (i = 0; i < m + 1; i++) qsort(h[i], l[i], sizeof *h[i], cmp);           // Röðum skiptingunum til að geta notað helmingunarleit.
	for (i = z = 0; i < (1 << n); z = count(++i))                               // Ítrum í gegnum öll hlutmengin í seinni skiptingunni.
	{
		if (x - z < 0 || x - z > m || t < u[i]) continue;                       // Skoðum hvort það sé mögulega hlutmengi sem passar.
		r += bs(h[x - z], t - u[i] + 1, l[x - z]);                              // Teljum hlutmengin í seinni skiptingunni sem passa við tiltekið
		r -= bs(h[x - z], t - u[i], l[x - z]);                                  //   hlutmengi með tveimur helmingunarleitum.
	}
	return r;
}

int main()
{
	int n, x, y, i, j, cc;
	scanf("%d", &n);                                                            // Innlestur hefst.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	scanf("%d%d", &x, &y);                                                      // Innlestri lokið.
	printf("%d\n", solve(a, a + n/2, n/2, (n + 1)/2, x, y));                    // Reiknum og prentum svarið.
	return 0;
}
