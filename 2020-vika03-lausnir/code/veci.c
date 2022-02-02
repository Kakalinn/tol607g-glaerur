#include <stdio.h>

int check(int a, int b)
{
	int c[10], i;
	for (i = 0; i < 10; i++) c[i] = 0;
	while (a > 0) c[a%10]++, a /= 10;
	while (b > 0) c[b%10]--, b /= 10;
	for (i = 0; i < 10; i++) if (c[i]) return 0;
	return 1;
}

int find(int n)
{
	int x = n + 1;
	while (x < 1000000 && !check(x, n)) x++;
	return x < 1000000 ? x : 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", find(n));
	return 0;
}
