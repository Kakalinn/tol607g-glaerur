#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef pair<int, int> ii;                                                      // Síðan koma m línur sem svara til leggjalistans.
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int prim(vvii& g, vii& mst)
{
    int i, x, y, w, n = g.size(), r = 0;
    vi v(n);                                                                    // Upphafstillum fylki sem geymir hvaða hnútar eru 'séðir'.
    mst = vii();                                                                // Tæmum fylkið sem mun geyma svarið.
    priority_queue<iii> q;                                                      // Upphafstillum forgangsbiðröðina.
    q.push(iii(-0, ii(0, -1)));                                                 // Setjum upphafshnútinn 0 í biðröðina.
    while (q.size() > 0)
    {
        iii p = q.top(); q.pop();                                               // Tökum fremsta stakið í forgagnsbiðröðinni.
        w = -p.first, x = p.second.first, y = p.second.second;                  // w, x og y þýða við komumst frá y til x eftir legg með vigt w.
        if (v[x] == 1) continue;                                                // Við erum búin að bæta x í tréð.
        if (y != -1) mst.push_back(ii(x, y));                                   // Bætum leggnum í svarið ef við erum ekki að afgreiða upphafshnútinn.
        r += w;                                                                 // Lögum stærðina.
        v[x] = 1;                                                               // Merkjum x 'séðann'.
        for (i = 0; i < g[x].size(); i++) if (v[g[x][i].first] == 0)            // Ítrum í gegnum all 'óséða' nágranna.
            q.push(iii(-g[x][i].second, ii(g[x][i].first, x)));                 // Bætum þeim í forgangsbiðröðina.
    }
    return r;                                                                   // Skilum stærðinni.
}

int main()
{
    int i, j, n, m, x, y, w;
    cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
    vvii g(n);
    vii mst;
    for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
    {
        cin >> x >> y >> w;                                                     // Tiltekinn leggur frá x til y með bigt w.
        x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
        g[x].push_back(ii(y, w));                                               // Bætum við legg frá x til y með vigt w.
        g[y].push_back(ii(x, w));                                               // Ef netið er óstefnt þarf að bæta við eins legg frá y to x, annars ekki.
    }
    printf("Staerdin a minnsta spannandi trenu er %d.\n", prim(g, mst));        // Reiknum og prentum stærðina.
    printf("Eftirfarandi leggir eru i minnsta spannandi tre netsins:\n");       // Prentum leggina í trénu.
    for (i = 0; i < n - 1; i++)
        printf("  (%d, %d)\n", mst[i].first + 1, mst[i].second + 1);
    return 0;
}
