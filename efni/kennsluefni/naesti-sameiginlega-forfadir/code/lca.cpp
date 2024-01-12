#include <bits/stdc++.h>
#define MAXN 100000
#define MAXK 17
// MAXK þarf að vera stærra en sirka log_2(MAXN)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int p[MAXN][MAXK], r[MAXN];
void lca_dfs(vvi& g, int x, int q, int w)                                       // Dýptarleit til að reikna metorð (w), foreldri (q) og stökk.
{
    int i;
    r[x] = w;
    for (i = 0; i < MAXK; i++) p[x][i] = (i == 0 ? q : p[p[x][i - 1]][i - 1]);  // Reiknum öll stökk af lengdum 2^k.
    for (i = 0; i < g[x].size(); i++) if (g[x][i] != q)                         // Ítrum í gegnum alla nágranna sem eru ekki foreldrið okkar.
        lca_dfs(g, g[x][i], x, w + 1);                                          // Höldum leitinni áfram.
}

void lca_init(vvi& g, int x)                                                    // Upphafstillir fyrir netið g með rót x.
{
    int i;
    for (i = 0; i < MAXK; i++) p[x][i] = x;                                     // Grunntilfellið.
    lca_dfs(g, x, x, 0);
}

int lca(int u, int v)                                                           // Skilar næsta sameiginlega forfaðir u og v.
{
    int i;
    if (r[u] < r[v]) swap(u, v);                                                // Tryggjum að u hafi hærra metorð.
    for (i = MAXK - 1; i >= 0; i--) if (r[p[u][i]] >= r[v]) u = p[u][i];        // Ferðumst að rótinni þar til u er með sama metorð og v.
    for (i = MAXK - 1; i >= 0; i--) if (p[u][i] != p[v][i])                     // Ferðumst að rótinni eftir lengstu stökkum þannig að u verði aldrei v.
        u = p[u][i], v = p[v][i];
    return u == v ? u : p[u][0];                                                // Skilum svarinu, sjá tilfellin í glærunum.
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

