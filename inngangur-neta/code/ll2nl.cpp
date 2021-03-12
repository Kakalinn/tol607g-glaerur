#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi nóða og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m, x, y;
	cin >> n >> m;
	vvi g(n);
	rep(i, m)
	{
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x); // Sleppa þesari línu ef netið er stefnt.
	}
	rep(i, n)
	{
		printf("%d: ", i + 1);
		rep(j, g[i].size()) printf("%d ", g[i][j] + 1);
		printf("\n");
	}
	return 0;
}
