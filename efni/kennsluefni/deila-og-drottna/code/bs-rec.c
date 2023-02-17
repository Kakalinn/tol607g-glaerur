#include <stdio.h>

int bs(int* a, int t, int l, int r)
{
	if (r - l == 1) return a[l] == t ? l : -1;                                  // Grunntilfelli.
	int m = (l + r)/2;                                                          // Helmingum listann.
	if (a[m] <= t) return bs(a, t, m, r);                                       // Hendum burt neðri helmingnum.
	else return bs(a, t, l, m);                                                 // Hendum burt efri helmingnum.
}

int main()
{
	int i, n, q, x;
	scanf("%d%d", &n, &q);                                                      // Innlestur hefst.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestri lokið.
	while (q-- != 0)                                                            // Keyrum q sinnum.
	{
		scanf("%d", &x);                                                        // Lesum inn töluna x.
		printf("%d\n", bs(a, x, 0, n));                                         // Finnur x í a að því gefnu að a sé raðaður.
	}
	return 0;
}
