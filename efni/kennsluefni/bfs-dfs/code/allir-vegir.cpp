#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v, p;
void dfs(vvi& g, int x)
{
	int i, f = 1;
	v[x] = 1;
	p.push_back(x);
	rep(i, g[x].size()) if (v[g[x][i]] == 0)
		dfs(g, g[x][i]), f = 0;
	if (f) { rep(i, p.size()) printf("%d ", p[i] + 1); printf("\n"); }
	p.pop_back();
	v[x] = 0;
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi nóða og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m;
	cin >> n >> m;
	vvi g(n);
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x); // Sleppa þesari línu ef netið er stefnt.
	}
	v = vi(n);
	rep(i, n) dfs(g, i);
	return 0;
}
