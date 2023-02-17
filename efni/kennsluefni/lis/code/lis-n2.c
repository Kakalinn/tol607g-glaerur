#include <stdio.h>
#include <string.h>
#define MAXN 1001
int max(int a, int b) { return a < b ? b : a; }

int v[MAXN], d[MAXN];
int dp_lookup(int x)                                                            // Finnur lengd lengstu vaxandi hlutruna a sem enda í staki x.
{
	if (d[x] != -1) return d[x];                                                // Við erum búin að reikna svarið. Skilum því.
	if (x == 0) return 1;                                                       // Lengsta vaxandi hlutruna tómu rununnar er af lengd núll.
	int i;
	for (d[x] = 1, i = 0; i < x; i++) if (v[i] <= v[x])                         // Skoðum alla vísa á undan x sem myndu mynda vaxandi hlutrunu.
		d[x] = max(d[x], dp_lookup(i) + 1);                                     // Finnum lengstu hlutrununa sem við getum skeytt framan á v[x].
	return d[x];                                                                // Skilum besta svarinu.
}

int lis(int *a, int n)                                                          // Finnur lengd lengstu vaxandi hlutruna a.
{
	int i, r = 1;
	for (i = 0; i < n; i++) d[i] = -1, v[i] = a[i];                             // Upphafstillum minnistöfluna.
	for (i = 0; i < n; i++) r = max(r, dp_lookup(i));                           // Finnum lengd lengstu vaxandi hlutrununa.
	return r;                                                                   // Skilum svarinu.
}

int main()
{
	int n, m, i, j;
	scanf("%d", &n);                                                            // Innlestur hafinn.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	printf("%d\n", lis(a, n));                                                  // Reiknum og skilum besta svarinu.
	return 0;
}
