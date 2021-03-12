#include <bits/stdc++.h>
#define rep(E, F) for (E = 0; E < (F); E++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int tsort(vvi& g, vi& t)
{
	int i, j, r = 1, n = g.size();
	vi d(n, 0);
	t = vi();
	int q[n], qe = 0, qs = 0;
	rep(i, n) rep(j, g[i].size()) d[g[i][j]]++;
	rep(i, n) if (d[i] == 0) q[qe++] = i;
	while (qe != qs)
	{
		if (qe - qs > 1) r = 2;
		int k = q[qs++];
		t.push_back(k);
		rep(i, g[k].size()) if (--d[g[k][i]] == 0) q[qe++] = g[k][i];
	}
	return t.size() != n ? 0 : r;
}

// Fyrsta lína inntaksins eru tvær heiltölur, fjöldi hnúta og fjöldi leggja.
// Síðan koma m línur sem svara til leggjalistans.
int main()
{
	int i, j, n, m, c = 0;
	cin >> n >> m;
	vi t;
	vvi g(n);
	rep(i, m)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
	}
	int r = tsort(g, t);
	printf(">>>>> %d\n", r);
	printf(">>>>> %d\n", t.size());
	if (!r) { printf("Netid er ekki orasad.\n"); return 0; }
	printf("Grannrodunin er");
	if (r == 2) printf(" ekki");
	printf(" otviraett akvordud.\n");
	rep(i, n) printf("%d ", t[i] + 1); printf("\n");
	return 0;
}
