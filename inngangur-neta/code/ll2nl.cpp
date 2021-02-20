#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi nóða og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m;
	cin >> n >> m;
	vvi g(n);
	for (i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x); // Sleppa þesari línu ef netið er stefnt.
	}
	for (i = 0; i < n; i++)
	{
		printf("%d: ", i + 1);
		for (j = 0; j < g[i].size(); j++) printf("%d ", g[i][j] + 1);
		printf("\n");
	}
	return 0;
}
