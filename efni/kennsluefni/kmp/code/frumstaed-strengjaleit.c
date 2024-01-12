#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void frumstaed_strengjaleit(char* s, int n, char* p, int m, int *r)
{
    int i, j;
    for (i = 0; i < n; i++) r[i] = 0;
    for (i = 0; i < n - m + 1; i++)
    {
        for (j = 0; j < m; j++) if (s[i + j] != p[j]) break;
        if (j >= m) r[i] = 1;
    }
}

int main()
{
    char *s, *p;
    scanf("%ms", &s);
    scanf("%ms", &p);
    int n = strlen(s), m = strlen(p), i, r[n];
    frumstaed_strengjaleit(s, n, p, m, r);
    for (i = 0; i < n; i++) if (r[i]) printf("<%s>\n", s + i);
    free(s), free(p);
    return 0;
}

