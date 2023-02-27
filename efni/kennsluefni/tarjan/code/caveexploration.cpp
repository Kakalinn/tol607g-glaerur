#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<ii> sii;
#define MAXN 200000

int a[MAXN], v[MAXN], curnum;                                                   // v[u] svara til u_{num} á glærunum.
vi cp; vii bri;
int dfs(const vvi &g, int u, int p, int d)
{
	int i, x, c = 0, z = d, y; v[u] = d;                                        // z svarar til u_{low} og y svara til v_{low}.
	for (i = 0; i < g[u].size(); i++) if (g[u][i] != p)                         // Ítrum í gegnum alla nágranna u nema þann sem við komum frá.
	{
		x = g[u][i];                                                            // x er nágranni u.
		if (v[x] == -1)
		{
			y = dfs(g, x, u, d + 1), c++;                                       // Heimsækjum x og lögum teljarann.
			z = min(z, y);                                                      // Uppfærum z ef þörf er á.
			if (y > v[u]) bri.push_back(ii(u, x));                              // Brú fundin, sjá glærur.
			if (p != -1 && y >= v[u]) a[u] = 1;                                 // Liðhnútur fundinn, sjá glærur.
		}
		else z = min(z, v[x]);                                                  // Það er búið að heimækja v, svo við gætum þurft að uppfæra z.
	}
	if (p == -1 && c > 1) a[u] = 1;                                             // Sértilfelli fyrir upphafshnútinn.
	return z;
}

void cpb(const vvi &g)
{
	cp.clear(), bri.clear();                                                    // Tæmum fyrri svör ef á er þörf.
	for (int i = 0; i < g.size(); i++) v[i] = -1, a[i] = 0;                     // Upphafstillum v með -1.
	for (int i = 0; i < g.size(); i++) if (v[i] == -1) dfs(g, i, -1, 0);        // Framkvæmum dýptarleitina fyrir hvern samhengisþátt.
	for (int i = 0; i < g.size(); i++) if (a[i]) cp.push_back(i);               // Setjum liðhnútana í cp.
}

void rem(vvi& g, ii p)
{
	int i;
	rep(i, g[p.first].size()) if (g[p.first][i] == p.second) break;
	g[p.first].erase(g[p.first].begin() + i);
	rep(i, g[p.second].size()) if (g[p.second][i] == p.first) break;
	g[p.second].erase(g[p.second].begin() + i);
}

int main()
{
	int n, m, i, j, x, y, r = 1;
	cin >> n >> m;
	vvi g(n);
	sii e;
	vi f(n);
	rep(i, m)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cpb(g);
	for (i = 0; i < bri.size(); i++) e.insert(bri[i]), e.insert(ii(bri[i].second, bri[i].first));
	int d[n], q[n], qe = 0, qs = 0;
	for (i = 0; i < n; i++) d[i] = -1;
	d[0] = 0;
	q[qe++] = 0;
	while (qe != qs)
	{
		int z = q[qs++];
		for (i = 0; i < g[z].size(); i++) if (d[g[z][i]] == -1 && e.find(ii(z, g[z][i])) == e.end()) q[qe++] = g[z][i], d[g[z][i]] = d[z] + 1, r++;
	}
	printf("%d\n", r);
	return 0;
}
