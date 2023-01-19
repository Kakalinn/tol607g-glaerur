#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 200000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int low[MAXN], num[MAXN], curnum;
vi cp; vii bri;
void dfs(const vvi &g, int u, int p)
{
	low[u] = num[u] = curnum++;
	int i, cnt = 0, f = 0;
	rep(i, g[u].size())
	{
		int v = g[u][i];
		if (num[v] == -1)
		{
			dfs(g, v, u);
			low[u] = min(low[u], low[v]);
			cnt++;
			f = f || low[v] >= num[u];
			if (low[v] > num[u]) bri.push_back(ii(u, v));
		}
		else if (p != v) low[u] = min(low[u], num[v]);
	}
	if (f && (p != -1 || cnt > 1)) cp.push_back(u);
}

void cpb(const vvi &g)
{
	int i, n = g.size();
	memset(num, -1, n << 2);
	curnum = 0;
	rep(i, n) if (num[i] == -1) dfs(g, i, -1);
}

int main()
{
	int i, j, n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n);
	rep(i, m)
	{
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cpb(g);
	printf("Alls eru %d bryr:\n", bri.size());
	rep(i, bri.size()) printf("%d %d\n", bri[i].first + 1, bri[i].second + 1);
	printf("Alls eru %d lidhnutar:\n", cp.size());
	rep(i, cp.size()) printf("%d\n", cp[i] + 1);
	return 0;
}
