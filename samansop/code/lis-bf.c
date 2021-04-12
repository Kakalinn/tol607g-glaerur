#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int main() {
	int n, i, j;
	scanf("%d", &n);
	int a[n];
	rep(i, n) scanf("%d", &a[i]);
	int mx = 0, mxi;
	rep(i, 1 << n)
	{
		int s[n], sc = 0;
		rep(j, n) if (((1 << j)&i) != 0) s[sc++] = a[j];
		rep(j, sc - 1) if (s[j + 1] < s[j]) break;
		if (j == sc - 1 && sc > mx) mx = sc, mxi = i;
	}
	printf("%d\n", mx);
	rep(i, n) if (((1 << i)&mxi) != 0) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
