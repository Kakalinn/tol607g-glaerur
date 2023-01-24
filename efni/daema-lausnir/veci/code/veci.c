#include <stdio.h>

int check(int a, int b)                                                         // Fall sem ákvarðar hvort a og b innihalda sömu tölustafi.
{
	int c[10], i;
	for (i = 0; i < 10; i++) c[i] = 0;                                          // Upphafstillum fylki sem geymir mismun hversu oft hver tala kemur fyrir.
	while (a > 0) c[a%10]++, a /= 10;                                           // Teljum hversu oft hver tala kemur fyrir í a.
	while (b > 0) c[b%10]--, b /= 10;                                           // Drögum frá hversu oft hver tala kemur fyrir í b.
	for (i = 0; i < 10; i++) if (c[i]) return 0;                                // Ef a og b innihalda sömu tölustafi má c bara innihalda 0.
	return 1;
}

int find(int n)                                                                 // Fall sem leysir dæmið.
{
	int x = n + 1;
	while (x < 1000000 && !check(x, n)) x++;                                    // Prófum allar mögulegar tölur stærri en n.
	return x < 1000000 ? x : 0;                                                 // Skilum x ef við fundum eitthvað.
}

int main()
{
	int n;
	scanf("%d", &n);                                                            // Innlestur.
	printf("%d\n", find(n));                                                    // Reiknum og prentum svarið.
	return 0;
}
