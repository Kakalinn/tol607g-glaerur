#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru þrjár heiltölur,
using namespace std;                                                            //   fjöldi hnúta, fjöldi leggja og upphafshnútinn.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;

vi v, p;
void dfs(vvi& g, int x)
{
	int i;
	v[x] = 1;                                                                   // Merkjum hnútinn sem 'séðan'.
	p.push_back(x);                                                             // Bætum x á veginn.
	for (i = 0; i < p.size(); i++) printf("%d ", p[i] + 1);                     // Prentum veginn.
	printf("\n");
	for (i = 0; i < g[x].size(); i++) if (v[g[x][i]] == 0)                      // Ítrum í gegnum alla nágranna sem eru ekki á veginum.
		dfs(g, g[x][i]);                                                        // Förum endurkvæmt í hnút g[x][i].
	p.pop_back();                                                               // Fjalægjum x úr veginum.
	v[x] = 0;                                                                   // Merkjum hnútinn aftur sem 'óséðan'.
}

int main()
{
	int i, j, n, m, x, y, u;
	cin >> n >> m >> u;                                                         // Lesum inn fjölda hnúta og fjölda leggja.
	u--;                                                                        // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
	vvi g(n);
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;                                                          // Tiltekinn leggur er frá hnút x til hnúts y.
		x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
		g[x].push_back(y);                                                      // Bætum við legg frá x til y.
		g[y].push_back(x);                                                      // Ef netið er óstefnt þarf að bæta við legg frá y to x, annars ekki.
	}
	v = vi(n);
	dfs(g, u);                                                                  // Prentum all einfalda vegi sem byrja í hnút 0.
	return 0;
}
