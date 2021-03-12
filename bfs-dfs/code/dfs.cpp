#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
void dfs(vvi& g, int x)
{
	int i;
	printf("Vid erum i nodu %d\n", x + 1);
	v[x] = 1;
	rep(i, g[x].size()) if (v[g[x][i]] == 0) dfs(g, g[x][i]);
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
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
	dfs(g, 0);
	return 0;
}
