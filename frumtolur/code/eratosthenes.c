#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 1000000

int e[MAXN];
void eratos()
{
	int i, j;
	rep(i, MAXN) e[i] = 1;
	e[0] = e[1] = 0;
	rep(i, MAXN) if (e[i] == 1) for (j = 2*i; j < MAXN; j += i) e[j] = 0;
}

int isp(int x)
{
	return e[x] == 1;
}

int main()
{
	int i, n;
	scanf("%d", &n);
	eratos();
	i = 0;
	rep(i, n) if (isp(i)) printf("%d ", i);
	printf("\n");
	return 0;
}
