#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

void nge(int* a, int* b, int n)
{
	int i, j;
	rep(i, n)
	{
		rep(j, n - i) if (a[i] < a[i + j]) break;
		b[i] = (j == n - i ? -1 : i + j);
	}
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int a[n], b[n];
	rep(i, n) scanf("%d", &a[i]);
	nge(a, b, n);
	rep(i, n) printf("%3d ", a[i]); printf("\n");
	rep(i, n) printf("%3d ", b[i]); printf("\n");
	return 0;
}
