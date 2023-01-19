#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnút og fjöldi leggja.
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
		g[y].push_back(ii(x, w)); // Sleppa þesari línu ef netið er stefnt.
	}
	printf("Nagrannar:\n");
	rep(i, n)
	{
		printf("%d: ", i + 1);
		rep(j, g[i].size()) printf("%d ", g[i][j].first + 1);
		printf("\n");
	}
	printf("Vigtir:\n");
	rep(i, n)
	{
		printf("%d: ", i + 1);
		rep(j, g[i].size()) printf("%d ", g[i][j].second);
		printf("\n");
	}
	return 0;
}
