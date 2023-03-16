#include <stdio.h>
#define MAXN 10000
typedef long long ll;

ll d[MAXN][MAXN], m;
ll dp_lookup(ll x, ll y)                                                        // Reiknum nCk.
{
    if (x < 0 || y < 0 || y > x) return 0;
    if (d[x][y] != -1) return d[x][y];
    if (y == 0 || y == x) return 1;
    return d[x][y] = (dp_lookup(x - 1, y - 1) + dp_lookup(x - 1, y))%m;
}

int main()
{
    ll i, j, n;
    scanf("%lld%lld", &n, &m);
    for (i = 0; i < MAXN; i++) for (j = 0; j < MAXN; j++) d[i][j] = -1;         // Upphafstillum minnistöfluna.
    for (i = 0; i < n; i++)                                                     // Prentum töflu yfir gildin.
    {
        for (j = 0; j < n - 1 - i; j++) printf("   ");
        for (j = 0; j < i + 1; j++) printf("%5lld ", dp_lookup(i, j));
        printf("\n");
    }
    return 0;
}
