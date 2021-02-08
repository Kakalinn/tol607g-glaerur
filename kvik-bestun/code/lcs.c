#include <stdio.h>
#include <string.h>
#define MAXN 10001
int max(int a, int b) { if (a < b) return b; return a; }

char s[10001], t[10001];
int d[MAXN][MAXN];
int dp_lookup(int x, int y)
{
	if (d[x][y] != -1) return d[x][y];
	if (x == 0 || y == 0) return 0;
	if (s[x - 1] == t[y - 1]) return d[x][y] = dp_lookup(x - 1, y - 1) + 1;
	return d[x][y] = max(dp_lookup(x - 1, y), dp_lookup(x, y - 1));
}

int main()
{
	int n, m, i, j;
	fgets(s, MAXN, stdin);
	fgets(t, MAXN, stdin);
	n = strlen(s) - 1;
	m = strlen(t) - 1;
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;
	printf("%d\n", dp_lookup(n, m));
	return 0;
}
