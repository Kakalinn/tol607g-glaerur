#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef pair<int, int> ii;

int isin(int x, int y, int r, int c)
{ // Segir okkur hvort (x, y) sé fyrir utan myndina okkar.
	if (x >= r || x < 0 || y >= c || y < 0) return 0;
	return 1;
}

int main()
{
	int i, j, r, c, x, y, g[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	cin >> r >> c;
	char a[r][c + 1];
	rep(i, r) cin >> a[i];
	rep(i, r) rep(j, c) if (a[i][j] == 'O') x = i, y = j;
	int d[r][c];
	rep(i, r) rep(j, c) d[i][j] = -1;
	queue<ii> q;
	q.push(ii(x, y)), d[x][y] = 0;
	while (q.size() > 0)
	{
		ii p = q.front(); q.pop();
		x = p.first, y = p.second;
		rep(i, 4)
		{
			int xx = x + g[i][0], yy = y + g[i][1];
			if (a[xx][yy] == 'X' || !isin(xx, yy, r, c) || d[xx][yy] != -1)
				continue;
			q.push(ii(xx, yy)), d[xx][yy] = d[x][y] + 1;
		}
	}
	rep(i, r) { rep(j, c) printf("%2d ", d[i][j]); printf("\n"); }
	return 0;
}
