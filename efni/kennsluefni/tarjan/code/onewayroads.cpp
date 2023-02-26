#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef set<ii> sii;
#define MAXN 200000
int low[MAXN], num[MAXN];
vi cp; sii bri;
int dfs(const vvi &g, int u, int p, int d)
{
	int i;
	low[u] = num[u] = d;
	for (i = 0; i < g[u].size(); i++)
	{
		int v = g[u][i];
		if (num[v] == -1)
		{
			dfs(g, v, u, d + 1);
			low[u] = min(low[u], low[v]);
			if (low[v] > num[u]) bri.insert(ii(u, v));
		}
		else if (p != v) low[u] = min(low[u], num[v]);
	}
	for (i = 0; i < g[u].size(); i++) if (low[g[u][i]] <= num[u]) break;
	if (i < g[u].size()) cp.push_back(u);
	if (p == -1 && g[u].size() > 1) cp.push_back(u);
	return d;
}

void cpb(const vvi &g)
{
	int i, n = g.size();
	bri.clear();
	cp.clear();
	for (i = 0; i < g.size(); i++) num[i] = -1;                                     // Upphafstillum num með -1.
	for (i = 0; i < g.size(); i++) if (num[i] == -1) dfs(g, i, -1, 0);                    // Framkvæmum dýptarleitina fyrir hvern samhengisþátt.
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
	int n, m, i, j, x, y;
	cin >> n >> m;
	vvi g(n);
	sii e;
	vi f(n);
	rep(i, m)
	{
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
		e.insert(ii(x, y));
	}
	cpb(g);
	if (bri.size() > 0)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	while (e.size() > 0)
	{
		ii p = *e.begin();
		printf("%d %d\n", p.first + 1, p.second + 1);
		e.erase(p);
		rem(g, p);
		queue<ii> q;
		q.push(p);
		while (q.size() > 0)
		{
			cpb(g);
			vii h;
			p = q.front(); q.pop();
			for (ii v : bri)
			{
				if (v.second == p.first) h.push_back(v);
				if (v.first == p.first) h.push_back(ii(v.second, v.first));
				if (v.first == p.second) h.push_back(v);
				if (v.second == p.second) h.push_back(ii(v.second, v.first));
			}
			rep(i, h.size())
			{
				printf("%d %d\n", h[i].first + 1, h[i].second + 1);
				rem(g, h[i]);
				e.erase(ii(h[i].second, h[i].first));
				e.erase(h[i]);
				q.push(h[i]);
			}
		}
	}
	return 0;
}
