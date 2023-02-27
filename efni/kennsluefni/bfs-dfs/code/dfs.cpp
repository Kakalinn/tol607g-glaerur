#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;

vi v;                                                                           // Í v er geymt hvort hnútur hafi verið heimsóttur eða ekki.
void dfs(vvi& g, int x)                                                         // Við erum í hnút x í netinu g.
{
	int i;
	printf("Vid erum i nodu %d\n", x + 1);
	v[x] = 1;                                                                   // Merkjum hnút x 'heimsóttan'.
	for (i = 0; i < g[x].size(); i++) if (v[g[x][i]] == 0)
		dfs(g, g[x][i]);                                                        // Heimsækjum alla nágranna x sem eru ekki 'heimsóttir'.
}

int main()
{
	int i, j, n, m, x, y;
	cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
	vvi g(n);
	for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
	{
		cin >> x >> y;                                                          // Tiltekinn leggur er frá hnút x til hnúts y.
		x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
		g[x].push_back(y);                                                      // Bætum við legg frá x til y.
		g[y].push_back(x);                                                      // Ef netið er óstefnt þarf að bæta við legg frá y to x, annars ekki.
	}
	v = vi(n);                                                                  // Upphafstillum v með n stökum sem eru öll 0.
	dfs(g, 0);                                                                  // Framkvæmum dýptarleit með 0 sem upphafshnútinn.
	return 0;
}
