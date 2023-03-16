#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
#define INF (1 << 30)                                                           //   fjöldi hnúta og fjöldi leggja.
using namespace std;                                                            // Síðan koma m línur sem svara til leggjalistans.
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi bellman_ford(vvii& g, int s)
{
    int i, j = 0, k, n = g.size(), x, w, q[2*n*n], p[n], a[n], qs = 0, qe = 0;
    vi d(n);
    q[qe] = s, p[qe++] = 0;                                                     // Setjum upphafshnútinn í biðröðina.
    for (i = 0; i < n; i++) d[i] = i == s ? 0 : INF, a[i] = i == s ? 1 : 0;     // Upphafstillum minnistölfuna með mjög stórri tölu.
    while (qe != qs)
    {
        i = q[qs], j = p[qs++], a[i] = 0;
        for (k = 0; k < g[i].size(); k++)                                       // Ítrum í gegnum alla nágranna tiltekins hnúts sem þarf að uppfæra.
        {
            x = g[i][k].first, w = g[i][k].second;
            if (d[x] != -INF && d[i] + w < d[x])
            {
                d[x] = j < n ? d[i] + w : -INF;                                 // Uppfærum og merkjum sem óendanlega rás ef stysti vegur minnkar of oft.
                if (!a[x]) a[x] = 1, q[qe] = x, p[qe++] = j + 1;                // Setjum hnútinn í biðröðina ef hann er ekki í biðröðinni.
            }
        }
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
