#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int f[MAXN], d[MAXN], p[MAXN];
void hld_init(vvi& g, int r)
{
    int i, j, n = g.size(), k = n, qs = 0, qe = 0, a[n], s[n], h[n];
    for (i = 0; i < n; i++)
        s[i] = 1, f[i] = i, p[i] = 0, d[i] = g[i].size() + (i == r);
    for (i = 0; i < n; i++) if (d[i] == 1) h[qe++] = a[--k] = i;                // Finnum grannröðun.
    for (i = h[qs++]; qs <= qe; i = h[qs++])
        for (j = 0; j < g[i].size(); j++) if (--d[g[i][j]] == 1)
            h[qe++] = g[i][j], a[--k] = g[i][j];
    for (i = 0; i < n; i++) d[i] = (i == r ? 0 : -1), h[i] = -1;                // Upphafstillum dýptir og þungu leggina.
    for (i = 0; i < n; i++) for (j = 0; j < g[a[i]].size(); j++)
        if (d[g[a[i]][j]] == -1) d[g[a[i]][j]] = d[a[i]] + 1;                   // Reiknum dýptir.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)
        if (d[i] == d[g[i][j]] + 1) p[i] = g[i][j];                             // Reiknum foreldri.
    for (i = n - 1; i >= 0; i--) if (i != 0) s[p[a[i]]] += s[a[i]];             // Reiknum stærðir undirtrjáa.
    for (i = 0; i < n; i++) if (i != r) h[p[i]] = i;                            // Veljum þunga leggi.
    for (i = 0; i < n; i++) if (i != r)
        h[p[i]] = s[h[p[i]]] < s[i] ? i : h[p[i]];                              // Veljum rétta þunga leggi.
    for (i = 0; i < n; i++) if (h[a[i]] != -1) f[h[a[i]]] = f[a[i]];            // Finnum þungu vegina.
}

int hld_lca(int u, int v)                                                       // Skilar næsta sameiginlega forfaðir u og v.
{
    while (f[u] != f[v]) (d[f[u]] > d[f[v]]) ? (u = p[f[u]]) : (v = p[f[v]]);   // Ferðumst að rótinni eftir þungu vegunum.
    return d[u] < d[v] ? u : v;                                                 // Skilum efri hnútinum því nú eru báðir hnútarnir á sama veg.
}

// slow implementation to compare.
int slow_p[MAXN], slow_d[MAXN], slow_v[MAXN];
void slow_dfs(vvi& g, int x, int w, int z)
{
    int i;
    slow_p[x] = w, slow_d[x] = z, slow_v[x] = -1;
    for (i = 0; i < g[x].size(); i++) if (!slow_v[g[x][i]]) slow_dfs(g, g[x][i], x, z + 1);
}

void slow_init(vvi& g, int r)
{
    int i;
    for (i = 0; i < g.size(); i++) slow_v[i] = 0;
    slow_dfs(g, r, r, 0);
}

int slow_lca(int u, int v)
{
    while (u != v)
    {
        if (slow_d[u] > slow_d[v]) u = slow_p[u];
        else v = slow_p[v];
    }
    return u;
}

void prufer2graph(int *a, int n, int *x, int *y)
{
    int i, j, k = 0, d[n], q[n], qe = 0, qs = 0;
    for (i = 0; i < n; i++) d[i] = 0;
    for (i = 0; i < n - 2; i++) d[a[i]]++;
    for (i = 0; i < n; i++) if (d[i] == 0) q[qe++] = i;
    for (i = 0; i < n - 2; i++)
    {
        j = q[qs++];
        x[k] = a[i], y[k] = j, x[k + 1] = j, y[k + 1] = a[i], k += 2, d[j]--, d[a[i]]--;
        if (d[a[i]] == 0) q[qe++] = a[i];
    }
    for (i = 0; i < n; i++) if (d[i] != -1) break;
    for (j = n - 1; j >= 0; j--) if (d[j] != -1) break;
    x[k] = i, y[k] = j, x[k + 1] = j, y[k + 1] = i, k += 2;
}

int main()
{
    srand(time(NULL));
    srand(101);
    int i, n = 100000, m = n - 1, q = 1000000, x[2*m], y[2*m], a[n - 2], r = rand()%n;
    vvi g(n);
    for (i = 0; i < n - 2; i++) a[i] = rand()%n;
    prufer2graph(a, n, x, y);
    for (i = 0; i < 2*m; i++) g[x[i]].push_back(y[i]);
    hld_init(g, r);
    slow_init(g, r);
    while (q--)
    {
        int x = rand()%n, y = rand()%n;
        printf("dink %d %d\n", x, y);
        printf(">> >>> (%d, %d) > slow, hld = %d, %d\n", x, y, slow_lca(x, y), hld_lca(x, y));
        assert(slow_lca(x, y) == hld_lca(x, y));
    }
    return 0;
}
