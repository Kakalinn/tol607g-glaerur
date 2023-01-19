#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
#define INF (1 << 30)
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int prim(vvii& g, vii& mst)
{
	int i, x, y, w, n = g.size(), r = 0;
	vi v(n); 
	mst = vii();
	priority_queue<iii> q;
	q.push(iii(-0, ii(0, -1)));
	while (q.size() > 0)
	{
		iii p = q.top(); q.pop();
		w = -p.first, x = p.second.first, y = p.second.second;
		if (v[x] == 1) continue;
		if (y != -1) mst.push_back(ii(x, y));
		r += w;
		v[x] = 1;
		rep(i, g[x].size()) if (v[g[x][i].first] == 0)
			q.push(iii(-g[x][i].second, ii(g[x][i].first, x)));
	}
	return r;
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m, x, y, w;
	cin >> n >> m;
	vii mst;
	vvii g(n);
	rep(i, m)
	{
		cin >> x >> y >> w;
		x--, y--;
		g[x].push_back(ii(y, w));
		g[y].push_back(ii(x, w));
	}
	printf("Staerdin a minnsta spannandi trenu er %d.\n", prim(g, mst));
	printf("Eftirfarandi leggir eru i minnsta spannandi tre netsins:\n");
	rep(i, n - 1) printf("  (%d, %d)\n", mst[i].first + 1, mst[i].second + 1);
	return 0;
}
