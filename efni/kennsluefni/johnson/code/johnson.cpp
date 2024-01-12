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
    ll i, j, k, m = s.size(), x, w, q[3 + 2*m*m], p[3 + 2*m*m];                 //   upphafstilltur með -1.
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

// Hægari lausn til samanburðar.
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

vvi many_bellman_fords(vvii& g)
{
    vvi d(g.size());
    for (ll i = 0; i < g.size(); i++) d[i] = bellman_ford_old(g, i);
    return d;
}

void compare(vvi &e, ll n, ll m)
{
    ll i, j;
    vvii g(n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (e[i][j] != INF) g[i].push_back(ii(j, e[i][j]));
    vvi d1 = johnson(g);
    vvi d2 = many_bellman_fords(g);
    for (i = 0; i < n; i++) { for (j = 0; j < n; j++) if (d1[i][j] != d2[i][j]) break; if (j < n) break; }
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
                if (d1[i][j] == -INF) printf(" -INF ");
                else if (d1[i][j] == INF) printf("  INF ");
                else printf("%5d ", d1[i][j]);
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
        printf("\n");
        assert(0);
    }
}

int main()
{
    srand(time(NULL));
    ll i, n = 200, m = 300, q = -1, x, y;
    vvi d(n, vi(n, INF));
    printf("generating graph\n");
    for (i = 0; i < m; )
    {
        x = rand()%n, y = rand()%n;
        if (x == y || d[x][y] != INF) continue;
        d[x][y] = rand()%200 - 100;
        i++;
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
