#include <stdio.h>
#include <stdlib.h>
#define MAXN 100000
int cmp(const void* p1, const void* p2)                                         // Samanburðarfall fyrir vaxandi röðun.
{
	int x = *(int*)p1, y = *(int*)p2;
	return (y <= x) - (x <= y);
}

int main()
{
    int i, n, a, e[MAXN];
	scanf("%d%d", &n, &a);                                                      // Innlestur hefst.
    for (i = 0; i < n; i++) scanf("%d", &e[i]);                                 // Innlestri lokið.
    qsort(e, n, sizeof *e, cmp);                                                // Röðum.
    for (i = 0; i < n; a -= e[i++] + 1) if (a < e[i] + 1) break;                // Veljum gráðugt minnstu sólkerfin fyrst.




    printf("%d\n", i);                                                          // Prentum svarið.
	return 0;
}

