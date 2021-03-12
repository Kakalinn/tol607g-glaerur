#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi v;
void dfs(vvi& g, int x, int c)
{
	int i;
	v[x] = c;
	rep(i, g[x].size()) if (v[g[x][i]] == -1) dfs(g, g[x][i], c);
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m, c = 0, x , y;
	cin >> n >> m;
	vvi g(n);
	rep(i, m)
	{
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	v = vi(n, -1);
	rep(i, n) if (v[i] == -1) dfs(g, i, c++);
	printf("Fjoldi samhengisthatta er %d.\n", c);
	rep(i, n) printf("Hnutur %d er i samhengisthaetti %d.\n", i + 1, v[i] + 1);
	return 0;
}
