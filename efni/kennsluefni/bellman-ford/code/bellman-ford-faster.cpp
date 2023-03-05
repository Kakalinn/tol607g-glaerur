#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
#define INF (1 << 30)                                                           //   fjöldi hnúta og fjöldi leggja.
using namespace std;                                                            // Síðan koma m línur sem svara til leggjalistans.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

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

int main()
{
    int i, j, n, m, x, y, w;
    cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
    vvii g(n);
    for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
    {
        cin >> x >> y >> w;                                                     // Tiltekinn leggur er frá hnút x til hnúts y.
        x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
        g[x].push_back(ii(y, w));                                               // Bætum við legg frá x til y.
    }
    vi d = bellman_ford(g, 0);                                                  // Reiknum svarið.
    for (i = 0; i < n; i++)                                                     // Prentum svarið.
    {
        printf("d[%d] = ", i);
        if (d[i] == INF) printf("Impossible\n");
        else if (d[i] == -INF) printf("-inf\n");
        else printf("%d\n", d[i]);
    }
    return 0;
}
