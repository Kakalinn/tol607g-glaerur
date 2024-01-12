#include <stdio.h>
#include <string.h>

int get_string(char *b, char t)
{ // Les inn i |b| streng af stadalinntaki fram að stafnum |t|.
    int i = 0, c = getchar();
    while (c != t && c != EOF) { b[i++] = c; c = getchar(); }
    b[i] = '\0';
    return i;
}

void prefix_function(char *p, int *b)                                           // Reiknar forstrengsfall p og geymir gildin í b.
{
    int i, j, m = strlen(p);
    for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
        while (j >= 0 && p[i] != p[j]) j = b[j];
}

void kmp(char *s, char *p, int *r)                                              // Eftir á segir r[i] hvort i-ti hlutstrengur s sé sá sami og p.
{
    int i, j, n = strlen(s), m = strlen(p), b[n + m + 2];
    char a[n + m + 2];
    strcpy(a, p), strcat(a, "\n"), strcat(a, s);
    prefix_function(a, b);
    for (i = 0; i < n; i++) r[i] = i < n - m + 1 && b[i + 2*m + 1] >= m;
}

int main()
{
    char s[1000001], p[1000001];
    int i, n, m;
    m = get_string(p, 10), n = get_string(s, 10);
    while (n)
    {
        int r[n];
        kmp(s, p, r);
        for (i = 0; i < n; i++) if (r[i]) printf("%d ", i); printf("\n");
        m = get_string(p, 10), n = get_string(s, 10);
    }
    return 0;
}
