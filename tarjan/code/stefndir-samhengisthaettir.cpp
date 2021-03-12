#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define MAXN 200000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int low[MAXN], num[MAXN], curnum, cnt;
vi cp, st, vis, ans;
void dfs(vvi &g, int u, int p)
{
	low[u] = num[u] = curnum++;
	st.push_back(u);
	vis[u] = 1;
	int i;
	rep(i, g[u].size())
	{
		int v = g[u][i];
		if (num[v] == -1) dfs(g, v, u);
		if (vis[v]) low[u] = min(low[u], low[v]);
	}
	if (low[u] == num[u])
	{
		while (1)
		{
			int v = st.back(); st.pop_back();
			vis[v] = 0; ans[v] = cnt;
			if (u == v) break;
		}
		cnt++;
	}
}

void scc(vvi &g)
{
	int i, n = g.size();
	vis = vi(n);
	ans = vi(n, -1);
	memset(num, -1, n << 2);
	curnum = cnt = 0;
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
	}
	scc(g);
	rep(i, n) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
