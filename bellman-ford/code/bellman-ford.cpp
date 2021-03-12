#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vi bellman_ford(vvii& g, int s)
{
	int i, j, k, n = g.size(), x, w;
	vi d(g.size(), INF);
	d[s] = 0;
	rep(i, n - 1) rep(j, n) if (d[j] != INF) rep(k, (int)g[j].size())
		d[g[j][k].first] = min(d[g[j][k].first], d[j] + g[j][k].second);
	rep(i, n - 1) rep(j, n) if (d[j] != INF) rep(k, (int)g[j].size())
	{
		x = g[j][k].first, w = g[j][k].second;
		if (d[x] != -INF && d[j] + w < d[x]) d[x] = -INF;
	}
	return d;
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m, x, y, w;
	cin >> n >> m;
	vvii g(n);
	rep(i, m)
	{
		cin >> x >> y >> w;
		x--, y--;
		g[x].push_back(ii(y, w));
		//g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
	}
	vi d = bellman_ford(g, 0);
	rep(i, n) printf("d[%d] = %d\n", i, d[i]);
	return 0;
}
