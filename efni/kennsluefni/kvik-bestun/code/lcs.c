#include <stdio.h>
#include <string.h>
#define MAXN 1001
int max(int a, int b) { if (a < b) return b; return a; }

char s[MAXN], t[MAXN];
int d[MAXN][MAXN];
int dp_lookup(int x, int y)
{ // Finnur lengd lengstu sameiginlegu hlutruna s[0:x] og t[0:y].
	if (d[x][y] != -1) return d[x][y];
	if (x == 0 || y == 0) return 0;
	if (s[x - 1] == t[y - 1]) return d[x][y] = dp_lookup(x - 1, y - 1) + 1;
	return d[x][y] = max(dp_lookup(x - 1, y), dp_lookup(x, y - 1));
}

int lcs(char *a, char *b)
{ // Finnur lengd lengstu sameiginlegu hlutruna strengjanna a og b.
	int i, j, n = strlen(a) - 1, m = strlen(b) - 1;
	strcpy(s, a), strcpy(t, b);
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;
	return dp_lookup(n, m);
}

int main()
{
	int n, m, i, j;
	char a[MAXN], b[MAXN];
	fgets(a, MAXN, stdin), fgets(b, MAXN, stdin);
	printf("%d\n", lcs(a, b));
	return 0;
}
