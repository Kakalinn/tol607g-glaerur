#include <bits/stdc++.h>
#define MAXN 100000
#define MAXK 17
// MAXK þarf að vera stærra en sirka log_2(MAXN)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int p[MAXN][MAXK], d[MAXN];
void lca_dfs(vvi& g, int x, int q, int w)
{ // Hjálparfall.
	int i;
	d[x] = w;
	for (i = 0; i < MAXK; i++) p[x][i] = i == 0 ? q : p[p[x][i - 1]][i - 1];
	for (i = 0; i < g[x].size(); i++) if (g[x][i] != q)
		lca_dfs(g, g[x][i], x, w + 1);
}

void lca_init(vvi& g, int x)
{ // Upphafstillir fyrir netið g með rót x.
	int i, n = g.size();
	for (i = 0; i < MAXK; i++) p[x][i] = x;
	lca_dfs(g, 0, x, x);
}

int lca(int u, int v)
{ // Skilar hæsta sameiginlega forfaðir u og v.
	int i;
	if (d[u] < d[v]) swap(u, v);
	for (i = MAXK - 1; i >= 0; i--) if (d[p[u][i]] >= d[v]) u = p[u][i];
	for (i = MAXK - 1; i >= 0; i--) if (p[u][i] != p[v][i])
		u = p[u][i], v = p[v][i];
	return u == v ? u : p[u][0];
}

#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int main()
{
    int x, y, i, j, n, m;
	scanf("%d%d", &n, &m);
    vvi g(n);
    rep(i, n - 1)
    {
		scanf("%d", &x);
		x--;
        g[x].push_back(i + 1);
        g[i + 1].push_back(x);
    }
	lca_init(g, 0);
    rep(i, m)
    {
		scanf("%d%d", &x, &y);
		x--, y--;
		printf("%s\n", lca(x, y) == y ? "No" : "Yes");
    }
    return 0;
}
