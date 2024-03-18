#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
#define INF (1LL << 30)

vvi floyd_warshall(vvii& g)
{
    ll i, j, k, n = g.size();
    vvi d(n, vi(n, INF));                                                       // Upphafstillum tvívíða minnistöflu með mjög stórri tölu.
    for (i = 0; i < n; i++) d[i][i] = 0;                                        // Lögum upphafsgildin á hornalínunni.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)                   // Ítrum í gegnum alla leggi netsins.
        d[i][g[i][j].first] = min(g[i][j].second, d[i][g[i][j].first]);         // Breytum nágrannalistunum í g í nágranna fylkið d.
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum í gegnum allar stöðurnar.
    {
        if (d[i][k] == INF || d[k][j] == INF) continue;                         // Getum ekki bætt ef gildið sem við erum í er óendalegt.
        d[i][j] = max(-INF, min(d[i][j], d[i][k] + d[k][j]));                   // Uppfærum ef þörf er á.
    }
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum aftur í gegnum allar stöðurnar til að finna áhrif neikvæðra rása.
    {
        if (d[i][k] == INF || d[k][j] == INF || d[i][j] == INF) continue;       // Getum ekki bætt ef gildið sem við erum í er óendanlegt.
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = -INF;                        // Ef við getum bætt er neikvæð rás á leiðinni.
    }
    return d;                                                                   // Skilum fjarlægðunum milli allra hnútanna.
}

int main()
{
    ll i, j, n, m, x, y, q, w, c = 0;
    cin >> n >> m >> q;                                                         // Lesum inn fjölda hnúta og fjölda leggja.
    while (n != 0)
    {
        vvii g(n);
        for (i = 0; i < m; i++)                                                 // Lesum inn leggina.
        {
            cin >> x >> y >> w;                                                 // Tiltekinn leggur er frá hnút x til hnúts y.
            g[x].push_back(ii(y, w));                                           // Bætum við legg frá x til y.
        }
        vvi d = floyd_warshall(g);
        while (q--)
        {
            cin >> x >> y;
            if (d[x][y] == INF) printf("Impossible\n");
            else if (d[x][y] == -INF) printf("-Infinity\n");
            else printf("%lld\n", d[x][y]);
        }
        printf("\n");
        cin >> n >> m >> q;                                                     // Lesum inn fjölda hnúta og fjölda leggja.
    }
    return 0;
}
