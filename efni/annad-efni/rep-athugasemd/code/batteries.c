#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

int d[5000], n;
int foo(int x)
{
    if (x == 1) return 0;
    if (d[x] != -1) return d[x];
    int i;
    d[x] = (1 << 30);
    rep(i, x) if (i != 0) d[x] = min(d[x], max(i, 1 + foo(x - i)));
    return d[x];
}

int main()
{
    int i;
    rep(i, 5000) d[i] = -1;
	scanf("%d", &n);
    while (n != 0)
    {
        printf("%d\n", foo(n));
		scanf("%d", &n);
    }
    return 0;
}
