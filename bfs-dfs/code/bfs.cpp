#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

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
	vi d(n, -1);
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (q.size() > 0)
	{
		int x = q.front();
		q.pop();
		rep(i, g[x].size()) if (d[g[x][i]] == -1)
		{
			q.push(g[x][i]);
			d[g[x][i]] = d[x] + 1;
		}
	}
	rep(i, n) printf("d[%d] = %d\n", i, d[i]);
	return 0;
}
