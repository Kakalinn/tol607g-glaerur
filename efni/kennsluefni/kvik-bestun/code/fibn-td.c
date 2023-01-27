#include <stdio.h>
#define MAXN 1000000
                                                                                // Hér geymum við skilagildi fib(...).
int d[MAXN];                                                                    // Ef d[i] = -1 þá eigum við eftir að reikna fib(i).
int fib(int x)
{
	if (d[x] != -1) return d[x];                                                // Við erum búin að reikna svarið. Skilum því.
	if (x < 2) return 1;                                                        // Grunntilfelli.
	return d[x] = fib(x - 1) + fib(x - 2);                                      // Reiknum og skilum svarinu.
}

int main()
{
	int n, i;
	scanf("%d", &n);                                                            // Innlestur.
	for (i = 0; i < n; i++) d[i] = -1;                                          // Upphafstillum minnistöfluna.
	printf("%d\n", fib(n - 1));                                                 // Reiknum of prentum svarið.
	return 0;
}
