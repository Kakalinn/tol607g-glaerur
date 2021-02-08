#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));

	int mx = 0, mask;
	for (i = 0; i < (1 << n); i++)
	{
		int s[n], c = 0;
		for (j = 0; j < n; j++) if (((1 << j)&i) != 0) s[c++] = j;
		for (j = 1; j < c; j++) if (a[s[j]] < a[s[j - 1]]) break;
		if (j == c && c > mx) mx = c, mask = i;
	}

	printf("%d\n", mx);
	for (i = 0; i < n; i++) if (((1 << i)&mask) != 0) printf("%d ", a[i]);
	printf("\n");

	return 0;
}
