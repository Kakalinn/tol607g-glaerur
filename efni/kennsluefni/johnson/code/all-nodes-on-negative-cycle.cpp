#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
typedef int ll;
#define INF (1LL << 30)                                                           //   fjöldi hnúta og fjöldi leggja.
using namespace std;                                                            // Síðan koma m línur sem svara til leggjalistans.
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

ll dfs(vvii& g, ll u, ll d, ll *s, ll *a, ll *l)                          // d svarar til u_{num}.
{
    l[u] = d, s[++s[0]] = u;                                                    // Upphafsstillum l og setjum u á hlaðann.
    ll i, x, z = d;
    for (i = 0; i < g[u].size(); i++)                                           // Ítrum í gegnum alla nágranna u.
    {
        x = g[u][i].first;
        if (l[x] == -1) d = dfs(g, x, d + 1, s, a, l);                          // Heimsækjum nágrannann.
        if (a[x] == -1) l[u] = min(l[u], l[x]);                                 // Uppfærum frá nágrannanum ef hann er ekki úr fyrri umferð.
    }
    if (l[u] == z) while (a[u] == -1) a[s[s[0]--]] = u;                         // Nýr samhengisþáttur. Merkjum hnútana í honum.
    return d;
}

void scc(vvii& g, ll *a)
{
    ll i, n = g.size(), s[n + 1], l[n];                                        // l[u] svarar til u_{low}.
    for (i = 0, s[0] = 0; i < n; i++) l[i] = a[i] = -1;                         // Upphafstillum a og l með -1.
    for (i = 0; i < n; i++) if (l[i] == -1) dfs(g, i, 0, s, a, l);              // Leitum með dýptarleit í öllu netinu.
}

vi bellman_ford(vvii& g, vi& s, vi& d, vi& a)
{
    ll i, j, k, m = s.size(), x, w, q[2 + 2*m*m], p[2 + 2*m*m];
    q[0] = q[1] = p[0] = p[1] = 2;
    for (i = 0; i < m; i++)
        d[s[i]] = 0, a[s[i]] = 1, q[q[1]++] = s[i], p[p[1]++] = 0;
    while (q[0] != q[1])
    {
        i = q[q[0]++], j = p[p[0]++], a[i] = 0;
        for (k = 0; k < g[i].size(); k++) if (a[g[i][k].first] != -1)                 // Ítrum í gegnum alla nágranna tiltekins hnúts sem þarf að uppfæra.
        {
            x = g[i][k].first, w = g[i][k].second;
            if (d[x] != -INF && d[i] + w < d[x])
            {
                d[x] = j < m ? d[i] + w : -INF;                                 // Uppfærum og merkjum sem óendanlega rás ef stysti vegur minnkar of oft.
                if (!a[x]) a[x] = 1, q[q[1]++] = x, p[p[1]++] = j + 1;                // Setjum hnútinn í biðröðina ef hann er ekki í biðröðinni.
            }
        }
    }
    return d;                                                                   // Skilum fjarlægðunum.
}

vi all_nodes_on_negative_cycle(vvii& g)
{
    ll i, j, n = g.size(), a[n];
    vi r(n), d(n), v(n);
    vvi s(n);
    scc(g, a);
    for (i = 0; i < n; i++) s[a[i]].push_back(i), v[i] = -1;
    for (i = 0; i < n; i++)
    {
        bellman_ford(g, s[i], d, v);
        for (j = 0; j < s[i].size(); j++) r[s[i][j]] = (d[s[i][j]] == -INF);
        for (j = 0; j < s[i].size(); j++) v[s[i][j]] = -1;
        for (j = 0; j < n; j++) assert(v[j] == -1);
    }
    return r;
}

#if 1
#if 1
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
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);                              // Uppfærum ef þörf er á.
    }
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum aftur í gegnum allar stöðurnar til að finna áhrif neikvæðra rása.
    {
        if (d[i][k] == INF || d[k][k] >= 0 || d[k][j] == INF) continue;       // Getum ekki bætt ef gildið sem við erum í er óendanlegt.
        d[i][j] = -INF;                        // Ef við getum bætt er neikvæð rás á leiðinni.
    }
    return d;                                                                   // Skilum fjarlægðunum milli allra hnútanna.
}
#endif
#if 0
vvi floyd_warshall(vvii& g)
{
    ll i, j, k, n = g.size();
    vector<vvi> d(n + 1, vvi(n, vi(n, INF)));
    for (i = 0; i < n; i++) d[0][i][i] = 0;
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)
        d[0][i][g[i][j].first] = min(g[i][j].second, d[0][i][g[i][j].first]);
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
    {
        //if (d[k][i][k] == INF || d[k][k][j] == INF) continue;
        d[k + 1][i][j] = min(d[k][i][j], d[k][i][k] + d[k][k][j]);
    }
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
    {
        if (d[n][i][k] == INF || d[n][k][k] >= 0 || d[n][k][j] == INF) continue;
        d[n][i][j] = -INF;
    }
    return d[n];
}
#endif
#if 0
vvi floyd_warshall(vvii& g)
{
    ll i, j, k, n = g.size();
    vvi d(n, vi(n, INF));                                                       // Upphafstillum tvívíða minnistöflu með mjög stórri tölu.
    for (i = 0; i < n; i++) d[i][i] = 0;                                        // Lögum upphafsgildin á hornalínunni.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)                   // Ítrum í gegnum alla leggi netsins.
        d[i][g[i][j].first] = min(g[i][j].second, d[i][g[i][j].first]);         // Breytum nágrannalistunum í g í nágranna fylkið d.
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        if (d[i][k] != INF && d[k][j] != INF)
            d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        if (d[i][k] != INF && d[k][k] < 0 && d[k][j] != INF)
            d[i][j] = -INF;
    return d;
}
#endif
#else
vi bellman_ford_old(vvii& g, ll s)
{
    ll i, j, k, f = 1, n = g.size(), x, w, q[n];
    vi d(n);
    for (i = 0; i < n; i++) d[i] = i == s ? 0 : INF, q[i] = i == s ? 0 : -1;    // Upphafstillum minnistölfuna með mjög stórri tölu.
    for (i = 0; f ; i++) for (j = f = 0; j < n; j++) if (q[j] == i)             // Ítrum í gegnum alla hnútanna nema þá sem við þurfum ekki að uppfæra.
        for (k = 0; k < g[j].size(); k++)                                       // Ítrum í gegnum alla nágranna tiltekins hnúts sem þarf að uppfæra.
        {
            x = g[j][k].first, w = g[j][k].second;
            if (d[x] != -INF && d[j] + w < d[x])
                d[x] = i < n ? d[j] + w : -INF, q[x] = i + 1, f = 1;                // Uppfærum ef við erum með betra gildi eða -INF.
        }
    return d;                                                                   // Skilum fjarlægðunum.
}

vvi floyd_warshall(vvii& g) // not really
{
    vvi d(g.size());
    for (ll i = 0; i < g.size(); i++) d[i] = bellman_ford_old(g, i);
    return d;
}
#endif

void compare(vvi &e, ll n, ll m)
{
    ll i, j;
    vvii g(n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (e[i][j] != INF) g[i].push_back(ii(j, e[i][j]));
    vi d1 = all_nodes_on_negative_cycle(g);
    vvi d2 = floyd_warshall(g);
    for (i = 0; i < n; i++) if (d1[i] && d2[i][i] != -INF || !d1[i] && d2[i][i] == -INF) break;
    if (i < n)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (e[i][j] == -INF) printf(" -INF ");
                else if (e[i][j] == INF) printf("  INF ");
                else printf("%5d ", e[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d2[i][j] == -INF) printf(" -INF ");
                else if (d2[i][j] == INF) printf("  INF ");
                else printf("%5d ", d2[i][j]);
            }
            printf("\n");
        }
        ll r = 0, s = 0;
        for (i = 0; i < n; i++) if (d1[i]) r++;
        for (i = 0; i < n; i++) if (d2[i][i] == -INF) s++;
        printf("found %d nodes (%d)\n", r, s);
        assert(0);
    }
    ll r = 0, s = 0;
    for (i = 0; i < n; i++) if (d1[i]) r++;
    for (i = 0; i < n; i++) if (d2[i][i] == -INF) s++;
    printf("found %d nodes (%d)\n", r, s);
}

#if 1
int main()
{
    //srand(time(NULL));
    srand(101);
    ll i, j, n = 200, m = 300, q = -1, x, y;
    vvi d(n, vi(n, INF));
    j = 0;
    printf("generating graph\n");
    while (j < m)
    {
        x = rand()%n, y = rand()%n;
        if (x == y || d[x][y] != INF) continue;
        d[x][y] = rand()%200 - 100;
        j++;
    }
    printf("graph generated\n");
    while (q--)
    {
        compare(d, n, m);
        x = rand()%n, y = rand()%n;
        while (x == y || d[x][y] == INF) x = rand()%n, y = rand()%n;
        d[x][y] = INF;
        x = rand()%n, y = rand()%n;
        while (x == y || d[x][y] != INF) x = rand()%n, y = rand()%n;
        d[x][y] = rand()%200 - 100;
        printf("test passed %d\n", q < 0 ? -q : q);
    }
    return 0;
}
#endif

#if 0
int main()
{
    ll i, j, n, m, x, y, w;
    cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
    vvii g(n);
    for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
    {
        cin >> x >> y >> w;                                                     // Tiltekinn leggur frá x til y með bigt w.
                                                                                //x--, y--;                                                             // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
        g[x].push_back(ii(y, w));                                               // Bætum við legg frá x til y með vigt w.
                                                                                //g[y].push_back(ii(x, w));                                             // Ef netið er óstefnt þarf að bæta við eins legg frá y to x, annars ekki.
    }
    vvi d = johnson(g);                                                         // Reiknum svarið.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] == -INF) printf(" -INF ");
            else if (d[i][j] == INF) printf("  INF ");
            else printf("%5d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    d = floyd_warshall(g);                                                      // Reiknum svarið.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (d[i][j] == -INF) printf(" -INF ");
            else if (d[i][j] == INF) printf("  INF ");
            else printf("%5d ", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
#endif
