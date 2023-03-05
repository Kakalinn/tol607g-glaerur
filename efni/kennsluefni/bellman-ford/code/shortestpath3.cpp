#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
#define INF (1 << 30)                                                           //   fjöldi hnúta og fjöldi leggja.
using namespace std;                                                            // Síðan koma m línur sem svara til leggjalistans.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

#if 1
vi bellman_ford(vvii& g, int s)
{
    int i, j, k, n = g.size(), x, w;
    vi d(g.size(), INF);                                                        // Upphafstillum minnistölfuna með mjög stórri tölu.
    d[s] = 0;                                                                   // Lögum grunntilfellið í núll.
    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (d[j] != INF)        // Ítrum í gegnum alla hnútanna nema þá sem við höfum ekki komið í.
        for (k = 0; k < g[j].size(); k++)                                       // Ítrum í gegnum alla nágranna tiltekins hnúts.
            d[g[j][k].first] = min(d[g[j][k].first], d[j] + g[j][k].second);    // Lögum minnistöfluna ef við erum með betri veg.
    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (d[j] != INF)        // Ítrum aftur í gegn til að finna áhrif neikvæðra rása.
        for (k = 0; k < g[j].size(); k++)
        {
            x = g[j][k].first, w = g[j][k].second;
            if (d[x] != -INF && d[j] + w < d[x]) d[x] = -INF;                   // Ef við getum ennþá stytt vegin er neikvæð rás á leiðinni.
        }
    return d;                                                                   // Skilum fjarlægðunum.
}
#else
vi bellman_ford(vvii& g, int s)
{
    int i, j, k, n = g.size(), x, w, q[n];
    vi d(n);
    for (i = 0; i < n; i++) d[i] = i == s ? 0 : INF, q[i] = i == s ? 0 : -1;    // Upphafstillum minnistölfuna með mjög stórri tölu.
    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (q[j] == i)          // Ítrum í gegnum alla hnútanna nema þá sem við þurfum ekki að uppfæra.
        for (k = 0; k < g[j].size(); k++)                                       // Ítrum í gegnum alla nágranna tiltekins hnúts sem þarf að uppfæra.
        {
            x = g[j][k].first, w = g[j][k].second;
            if (d[j] + w < d[x]) d[x] = d[j] + w, q[x] = i + 1;                 // Uppfærum ef við erum með betra gildi.
        }
    for (i = 0; i < n - 1; i++) for (j = 0; j < n; j++) if (q[j] == n + i - 1)  // Ítrum aftur í gegn til að finna áhrif neikvæðra rása.
        for (k = 0; k < g[j].size(); k++)
        {
            x = g[j][k].first, w = g[j][k].second;
            if (d[x] != -INF && d[j] + w < d[x]) d[x] = -INF, q[x] = n + i;     // Ef við getum ennþá stytt vegin er neikvæð rás á leiðinni.
        }
    return d;                                                                   // Skilum fjarlægðunum.
}
#endif
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int()
{
    int r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}
int main()
{
    int i, j, x, y, z, n = get_int(), m = get_int(), q = get_int(), s = get_int();
    while (n != 0)
    {
        vvii g(n);
        rep(i, m)
        {
            x = get_int(), y = get_int(), z = get_int();
            g[x].emplace_back(y, z);
        }
        vi d = bellman_ford(g, s);
        while (q-- != 0)
        {
            x = get_int();
            if (d[x] == INF) printf("Impossible\n");
            else if (d[x] == -INF) printf("-Infinity\n", d[x]);
            else printf("%d\n", d[x]);
        }
        n = get_int(), m = get_int(), q = get_int(), s = get_int();
    }

    return 0;
}

