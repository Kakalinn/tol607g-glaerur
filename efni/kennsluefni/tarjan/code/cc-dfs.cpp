#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;

vi v;
void dfs(vvi& g, int x, int c)
{
	int i;
	v[x] = c;                                                                   // Merkjum að x sé í samhengisþætti c.
	for (i = 0; i < g[x].size(); i++) if (v[g[x][i]] == -1)                     // Höldum áfram leit í öllum 'óséðu' nágrönnum.
		dfs(g, g[x][i], c);
}

int main()
{
	int i, j, n, m, c = 0, x , y;
	cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
	vvi g(n);
	for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
	{
		cin >> x >> y;                                                          // Tiltekinn leggur er frá hnút x til hnúts y.
		x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
		g[x].push_back(y);                                                      // Bætum við legg frá x til y.
		g[y].push_back(x);                                                      // Netið er óstefnt svo það þarf að bæta við legg frá y to x.
	}
	v = vi(n, -1);                                                              // Upphafstillum alla hnúta sem 'óséða', með -1.
	for (i = 0; i < n; i++) if (v[i] == -1) dfs(g, i, c++);                     // Framkvæmum dýptarleit á alla 'óséða' hnúta.
	printf("Fjöldi samhengisþátta er %d.\n", c);
	for (i = 0; i < n; i++)
		printf("Hnútur %d er í samhengisþætti %d.\n", i + 1, v[i] + 1);
	return 0;
}
