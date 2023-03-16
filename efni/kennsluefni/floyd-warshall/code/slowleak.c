#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define INF 1000000000000000000LL
#define MAXN 502
#define rep(E, F) for (E = 0; E < (F); E++)
typedef long long ll;
ll min(ll a, ll b) { if (a > b) { return b; } return a; }
ll max(ll a, ll b) { if (a < b) { return b; } return a; }

ll get_int()
{
    ll r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}

ll a[MAXN][MAXN];
void floyd_warshall(int n)
{
    ll i, j, k;
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum í gegnum allar stöðurnar.
    {
        if (a[i][k] == INF || a[k][j] == INF) continue;                         // Getum ekki bætt ef gildið sem við erum í er óendalegt.
        a[i][j] = min(a[i][j], a[i][k] + a[k][j]);                              // Uppfærum ef þörf er á.
    }
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum aftur í gegnum allar stöðurnar til að finna áhrif neikvæðra rása.
    {
        if (a[i][k] == INF || a[k][j] == INF || a[i][j] == INF) continue;       // Getum ekki bætt ef gildið sem við erum í er óendanlegt.
        if (a[i][k] + a[k][j] < a[i][j]) a[i][j] = -INF;                        // Ef við getum bætt er neikvæð rás á leiðinni.
    }
}

int main()
{
    ll i, j, k, n = get_int(), m = get_int(), t = get_int(), d = get_int();
    ll s[t + 2], b[t + 2][t + 2];
    s[0] = 0, s[1] = n - 1;
    rep(i, t) s[i + 2] = get_int() - 1;
    rep(i, n) rep(j, n) a[i][j] = INF;
    rep(i, m)
    {
        ll x = get_int() - 1, y = get_int() - 1, z = get_int();
        a[x][y] = a[y][x] = z;
    }
    rep(i, n) a[i][i] = 0;

    floyd_warshall(n);
    //rep(i, n) { rep(j, n) printf("%2lld ", a[i][j] != INF ? a[i][j] : -1); printf("\n"); }

    rep(i, t + 2) rep(j, t + 2) b[i][j] = INF;
    rep(i, t + 2) rep(j, t + 2) if (a[s[i]][s[j]] <= d) b[i][j] = a[s[i]][s[j]];
    rep(i, t + 2) rep(j, t + 2) a[i][j] = b[i][j];
    //rep(i, n) { rep(j, n) printf("%2lld ", a[i][j] != INF ? a[i][j] : -1); printf("\n"); }

    //rep(i, t + 2) { rep(j, t + 2) printf("%2lld ", b[i][j] != INF ? b[i][j] : -1); printf("\n"); } printf("\n");
    floyd_warshall(t + 2);

    //rep(i, t + 2) { rep(j, t + 2) printf("%2lld ", b[i][j] != INF ? b[i][j] : -1); printf("\n"); }
    if (a[0][1] != INF) printf("%lld\n", a[0][1]);
    else printf("stuck\n");

    return 0;
}
