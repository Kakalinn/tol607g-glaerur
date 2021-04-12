#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

void nge(int* a, int* b, int n)
{
	int s[n], c = 0, i;
	rep(i, n)
	{
		while (c > 0 && a[s[c - 1]] < a[i]) b[s[--c]] = i;
		s[c++] = i;
	}
	while (c > 0) b[s[--c]] = -1;
}

int main()
{
	int i, n;
	printf("Staerd listans: "); fflush(stdout);
	scanf("%d", &n);
	int a[n], b[n];
	printf("%d tolur: ", n); fflush(stdout);
	rep(i, n) scanf("%d", &(a[i]));
	nge(a, b, n);
	printf("NGE:\n");
	rep(i, n) printf("%8d ", a[i]); printf("\n");
	rep(i, n) printf("%8d ", (b[i] != -1 ? a[b[i]] : -1)); printf("\n");
	return 0;
}
