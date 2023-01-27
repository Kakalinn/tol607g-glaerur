#include <stdio.h>

int fib(int x)
{
	if (x < 3) return 1;                                                        // Grunntilfelli.
	return fib(x - 1) + fib(x - 2);                                             // Reiknum og skilum svarinu.
}

int main()
{
	int n;
	scanf("%d", &n);                                                            // Innlestur.
	printf("%d\n", fib(n));                                                     // Reiknum of prentum svarið.
	return 0;
}
