#include <stdio.h>
#include <string.h>
#define MAXN 1001
int max(int a, int b) { if (a < b) return b; return a; }

char s[MAXN], t[MAXN];
int d[MAXN][MAXN];
int dp_lookup(int x, int y)                                                     // Skilar lengd lengstu sameiginlegu hlutruna s[0:x] og t[0:y].
{
    if (d[x][y] != -1) return d[x][y];                                          // Við erum búin að reikna besta svarið. Skilum því.
    if (x == 0 || y == 0) return 0;                                             // Grunntilfelli.
    if (s[x - 1] == t[y - 1]) return d[x][y] = dp_lookup(x - 1, y - 1) + 1;     // Bætum staf við besta svarið.
    return d[x][y] = max(dp_lookup(x - 1, y), dp_lookup(x, y - 1));             // Prófum báða möguleikana í boði.
}

int lcs(char *a, char *b)                                                       // Finnur lengd lengstu sameiginlegu hlutruna strengjanna a og b.
{
    int i, j, n = strlen(a) - 1, m = strlen(b) - 1;
    strcpy(s, a), strcpy(t, b);
    for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++) d[i][j] = -1;       // Upphafstillum minnistöfluna.
    return dp_lookup(n, m);                                                     // Skilum svarinu.
}

int main()
{
    int n, m, i, j;
    char a[MAXN], *b = "abcdefghijklmnopqrstuvwxyz";
    fgets(a, MAXN, stdin);                                                      // Innlestur.
    printf("%d\n", 26 - lcs(a, b));                                             // Reiknum og prentum svarið.
    return 0;
}
