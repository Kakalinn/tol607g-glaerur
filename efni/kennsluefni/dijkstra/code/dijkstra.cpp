#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
#define INF (1 << 30)                                                           //   fjöldi hnúta og fjöldi leggja.
using namespace std;                                                            // Síðan koma m línur sem svara til leggjalistans.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi dijkstra(vvii& g, int s)
{
    int i, x, w, n = g.size();
    vi d(n, INF);                                                               // Upphastillum stystu lengdirnar sem við höfum fundið.
    priority_queue<ii> q;                                                       // Forgangsbiðröð fyrir tvenndirnar (gildi, hnútur).
    q.push(ii(-0, s)), d[s] = 0;                                                // Setjum upphafshnútinn í forgangsbiðröðina og upphastillum gildið.
    while (q.size() > 0)
    {
        w = -q.top().first, x = q.top().second, q.pop();                        // Veljum 'ókláraða' hnútinn með minnsta gildið.
        if (w > d[x]) continue;                                                 // Þetta er úrelt gildi.
        for (i = 0; i < g[x].size(); i++)                                       // Ítrum í gegnum alla nágranna x.
        {
            if (d[g[x][i].first] <= w + g[x][i].second) continue;               // Það borgar sig ekki að ferðast frá x í g[x][i].
            q.push(ii(-(w + g[x][i].second), g[x][i].first));                   // Það borgar sig. Bætum g[x][i] í forgangsbiðröðina með nýju (minna)
            d[g[x][i].first] = w + g[x][i].second;                              //   gildi og stillum gildið.
        }
    }
    return d;
}

int main()
{
    int i, j, n, m, x, y, w;
    cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
    vvii g(n);
    for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
    {
        cin >> x >> y >> w;                                                     // Tiltekinn leggur frá x til y með bigt w.
        x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
        g[x].push_back(ii(y, w));                                               // Bætum við legg frá x til y með vigt w.
        g[y].push_back(ii(x, w));                                               // Ef netið er óstefnt þarf að bæta við eins legg frá y to x, annars ekki.
    }
    vi d = dijkstra(g, 0);                                                      // Reiknum svarið.
    for (i = 0; i < n; i++) printf("d[%d] = %d\n", i, d[i]);                    // Prentum fjarlægðina frá 0 í alla hnúta.
    return 0;
}
