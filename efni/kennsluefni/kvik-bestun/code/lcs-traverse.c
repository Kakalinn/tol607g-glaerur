#include <stdio.h>
#include <string.h>
#define MAXN 1001
int max(int a, int b) { if (a < b) return b; return a; }
char s[MAXN], t[MAXN];
int d[MAXN][MAXN];
int dp_lookup(int x, int y)                                                     // Skilar lengd lengstu sameiginlegu hlutrurn s[0:x] og t[0:y].
{
	if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna besta svarið. Skilum því.
	if (x == 0 || y == 0) return 0;                                             // Grunntilfelli.
	if (s[x - 1] == t[y - 1]) return d[x][y] = dp_lookup(x - 1, y - 1) + 1;     // Bætum staf í besta svarið.
	return d[x][y] = max(dp_lookup(x - 1, y), dp_lookup(x, y - 1));             // Prófum báða möguleikana í boði.
}

int lcs(char *a, char *b, char *r)                                              // Finnur einn af lengstu sameiginlegu hlutrunu strengjanna a og b.
{
	int i, j, k, n = strlen(a) - 1, m = strlen(b) - 1, x, y;
	strcpy(s, a), strcpy(t, b), memset(r, '\0', MAXN);
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;       // Upphafstillum minnistöfluna.
	for (k = dp_lookup(n, m), x = n, y = m; x > 0 && y > 0; )                   // Finnum einn af lengstu sameiginlegu hlutrunum a og b.
	{
		if (s[x - 1] == t[y - 1]) r[--k] = s[x - 1], x--, y--;                  // Bætum staf í besta svarið.
		else (dp_lookup(x, y - 1) > dp_lookup(x - 1, y)) ? y-- : x--;           // Minnkum eftir því hvort er betra.
	}
	return dp_lookup(n, m);                                                     // Skilum bestu lengdinni.
}

int main()
{
	int n, m, k, i;
	char a[MAXN], b[MAXN], r[MAXN];
	fgets(a, MAXN, stdin), fgets(b, MAXN, stdin);                               // Innlestur.
	k = lcs(a, b, r);                                                           // Reiknum svarið.
	printf("%s\n", r);                                                          // Prentum svarið.
	return 0;
}
