#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 1000000

int e[MAXN];
void eratos()
{
	int i, j;
	rep(i, MAXN) e[i] = 0;
	e[0] = e[1] = -1;
	rep(i, MAXN) if (e[i] == 0)
		for (j = i; j < MAXN; j += i) if (e[j] == 0) e[j] = i;
}

void factor(int x)
{
	if (x < 2) return;
	printf("%d ", e[x]);
	factor(x/e[x]);
}

int isp(int x)
{
	return e[x] == x;
}

int main()
{
	int i, n;
	eratos();
	while (scanf("%d", &n) != EOF)
	{
		if (isp(n)) printf("The number %d is prime.\n", n);
		else printf("The number %d is composite.\n", n);
		printf("It's factors are: ");
		factor(n);
		printf("\n");
	}
	return 0;
}
