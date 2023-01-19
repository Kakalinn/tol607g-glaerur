#include <stdio.h>
#define MAXN 1000000

int d[MAXN];
int dp_lookup(int x)
{
	if (d[x] != -1) return d[x];
	if (/* Er þetta grunntilfelli? */)
	{
		/* Skila tilheyrandi grunnsvari */
	}
	/* Reikna d[x] */
	return d[x];
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < MAXN; i++) d[i] = -1;
	printf("%d\n", dp_lookup(n));
	return 0;
}
