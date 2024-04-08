#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int p[MAXN], r[MAXN];
void lca_dfs(vvi& g, int x, int q, int w)                                       // Dýptarleit til að reikna metorð (w) og foreldri (q).
{
    r[x] = w, p[x] = q;                                                         // Reiknum foreldri og metorð.
    for (int i = 0; i < g[x].size(); i++) if (g[x][i] != q)                     // Ítrum í gegnum alla nágranna sem eru ekki foreldrið okkar.
        lca_dfs(g, g[x][i], x, w + 1);                                          // Höldum leitinni áfram.
}

void lca_init(vvi& g, int x)                                                    // Upphafstillir fyrir netið g með rót x.
{
    lca_dfs(g, x, x, 0);
}

int lca(int u, int v)                                                           // Skilar næsta sameiginlega forfaðir u og v.
{
    if (r[u] < r[v]) swap(u, v);                                                // Tryggjum að u hafi hærra metorð.
    while (r[u] != r[v]) u = p[u];                                              // Ferðumst að rótinni þar til u er með sama metorð og v.
    while (u != v) u = p[u], v = p[v];                                          // Ferðumst upp þar til hnútarnir eru eins.
    return u;                                                                   // Skilum hnútnum sem við endum í.
}

int main()
{
    int x, y, i, j, n, m;
    scanf("%d%d", &n, &m);
    vvi g(n);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &x);
        x--;
        g[x].push_back(i + 1);
        g[i + 1].push_back(x);
    }
    lca_init(g, 0);
    for (i = 0; i < m; i++)
    {
        scanf("%d%d", &x, &y);
        x--, y--;
        printf("Næsti sameiginlegi forfaðir %d og %d er %d\n", x + 1, y + 1, lca(x, y) + 1);
    }
    return 0;
}

