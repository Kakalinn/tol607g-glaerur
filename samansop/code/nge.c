#include <stdio.h>

void nge(int* a, int* b, int n)
{
	int s[n], c = 0, i;
	for (i = 0; i < n; i++)
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
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));
	nge(a, b, n);
	printf("NGE:\n");
	for (i = 0; i < n; i++) printf("%8d ", a[i]); printf("\n");
	for (i = 0; i < n; i++) printf("%8d ", (b[i] != -1 ? a[b[i]] : -1)); printf("\n");
	return 0;
}
