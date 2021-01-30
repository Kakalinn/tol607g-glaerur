#include <stdio.h>

int fib(int x)
{
	if (x < 3) return 1;
	return fib(x - 1) + fib(x - 2);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", fib(n));
	return 0;
}
