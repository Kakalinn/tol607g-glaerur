#include <bits/stdc++.h>
typedef long long ll;
#define INF (1LL << 60)
using namespace std;
typedef pair<ll, ll> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<ll> vi;
typedef vector<vi> vvi;

vi dijkstra(vvii& g, ll s)
{
    ll i, x, w, n = g.size();
    vi d(n, INF);
    priority_queue<ii> q;
    q.push(ii(-0, s)), d[s] = 0;
    while (q.size() > 0)
    {
        w = -q.top().first, x = q.top().second, q.pop();
        if (w > d[x]) continue;
        for (i = 0; i < g[x].size(); i++)
        {
            if (d[g[x][i].first] <= w + g[x][i].second) continue;
            q.push(ii(-(w + g[x][i].second), g[x][i].first));
            d[g[x][i].first] = w + g[x][i].second;
        }
    }
    return d;
}

ll dfs(vvii& g, ll u, ll d, ll *s, ll *a, ll *l)                                // d svarar til u_{num}.
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
    ll i, n = g.size(), s[n + 1], l[n];                                         // l[u] svarar til u_{low}.
    for (i = 0, s[0] = 0; i < n; i++) l[i] = a[i] = -1;                         // Upphafstillum a og l með -1.
    for (i = 0; i < n; i++) if (l[i] == -1) dfs(g, i, 0, s, a, l);              // Leitum með dýptarleit í öllu netinu.
}

void bellman_ford(vvii& g, vi& s, vi& d, vi& a)                                 // Reiknirit Bellmans og Fords þar sem allir hnútar eru upphafshnútar,
{                                                                               //   en það er aðeins ferðast eftir hnútum í s. Listinn a þarf að vera
    ll i, j, k, m = s.size(), x, w, q[2 + 2*m*m], p[2 + 2*m*m];                 //   upphafstilltur með -1.
    q[0] = q[1] = p[0] = p[1] = 2;
    for (i = 0; i < m; i++)
        d[s[i]] = 0, a[s[i]] = 1, q[q[1]++] = s[i], p[p[1]++] = 0;
    while (q[0] != q[1])
    {
        i = q[q[0]++], j = p[p[0]++], a[i] = 0;
        for (k = 0; k < g[i].size(); k++) if (a[g[i][k].first] != -1)           // Ítrum í gegnum alla nágranna tiltekins hnúts sem þarf að uppfæra.
        {
            x = g[i][k].first, w = g[i][k].second;
            if (d[x] != -INF && d[i] + w < d[x])
            {
                d[x] = j < m ? d[i] + w : -INF;                                 // Uppfærum og merkjum sem óendanlega rás ef stysti vegur minnkar of oft.
                if (!a[x]) a[x] = 1, q[q[1]++] = x, p[p[1]++] = j + 1;          // Setjum hnútinn í biðröðina ef hann er ekki í biðröðinni.
            }
        }
    }
}

vi all_nodes_on_negative_cycle(vvii& g)
{
    ll i, j, n = g.size(), a[n];
    vi r(n), d(n), v(n);
    vvi s(n);
    scc(g, a);                                                                  // Finnum alla stranga samhengisþætti g.
    for (i = 0; i < n; i++) s[a[i]].push_back(i), v[i] = -1;                    // Hópum saman hnútum sem eru í sama stranga samhengisþætti.
    for (i = 0; i < n; i++)
    {
        bellman_ford(g, s[i], d, v);                                            // Reiknum hvort það sé neikvæð rás í stranga samhengisþættinum.
        for (j = 0; j < s[i].size(); j++) r[s[i][j]] = (d[s[i][j]] != -INF);
        for (j = 0; j < s[i].size(); j++) v[s[i][j]] = -1;                      // Pössum að öll gildin í v séu -1 fyrir næsta kall á bellman_ford(...).
    }
    return r;
}

vvi johnson(vvii &g)
{
    ll i, j, n = g.size(), x, w;
    vi s, b = all_nodes_on_negative_cycle(g), c(n, -1), h(n, -INF);             // Finnum alla hnútana sem eru á einhverri neikvæðri rás.
    for (i = 0; i < n; i++) if (b[i]) s.push_back(i);                           // Setjum í lista þá hnúta sem eru ekki á neikvæðri rás.
    bellman_ford(g, s, h, c);                                                   // Reiknum stysta veg sem endar í hnútunum í netinu með hnútum úr s.
    vvi d(n);
    vvii q(2*n);                                                                // Gerum nýja tvöfalda netið.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)                   // Ítrum í gegnum alla leggi.
    {
        x = g[i][j].first, w = g[i][j].second;
        if (h[x] == -INF) q[i].push_back(ii(x + n, 0));                         // Leggurinn fer inn í neikvæða rás, svo við fáum legg upp á aðra hæð.
        else if (h[i] != -INF) q[i].push_back(ii(x, w + h[i] - h[x]));          // Leggurinn fer ekki inn í neikvæða rás. Gerum leggin jákvæðan.
        q[i + n].push_back(ii(x + n, 0));                                       // Afritum legginn á aðra hæð.
    }
    for (i = 0; i < n; i++) d[i] = dijkstra(q, i);                              // Reiknum fjarlægðir í nýja netinu.
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)                             // Lögum fjarlægðirnar sem eiga ekki að vera -INF.
        if (d[i][j] != INF) d[i][j] = d[i][j] - h[i] + h[j];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)                             // Lögum fjarlægðirnar sem eiga að vera -INF.
        if (d[i][j + n] != INF) d[i][j] = -INF;
    for (i = 0; i < n; i++) d[i].resize(n);                                     // Klippum burt efri hæðina.
    return d;                                                                   // Skilum öllum fjarlægðunum.
}

int main()
{
    ll i, j, n, m, x, y, w, q;
    cin >> n >> m >> q;
    while (n)
    {
        vvii g(n);
        for (i = 0; i < m; i++)
        {
            cin >> x >> y >> w;
            g[x].push_back(ii(y, w));
        }
        vvi d = johnson(g);
        while (q--)
        {
            cin >> x >> y;
            if (d[x][y] <= -INF) printf("-Infinity\n");
            else if (d[x][y] >= INF) printf("Impossible\n");
            else printf("%d\n", d[x][y]);
        }
        printf("\n");
        cin >> n >> m >> q;
    }
    return 0;
}
