#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;

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
	vi d(n, -1);                                                                // Upphafstillum alla hnúta sem 'óséða', með -1.
	queue<int> q;
	q.push(0);                                                                  // Látum upphafshnútinn í biðröðina
	d[0] = 0;                                                                   //   og merkjum hann sem 'séðann'.
	while (q.size() > 0)                                                        // Hættum ekki fyrr en biðröðin er tóm, þ.e. allir hnútar 'kláraðir'.
	{
		int x = q.front();                                                      // Veljum fremst hnútinn í biðröðinni
		q.pop();                                                                //   og fjarlægjum hann.
		for (i = 0; i < g[x].size(); i++) if (d[g[x][i]] == -1)                 // Ítrum í gegnum alla 'óséða' nágranna hnútsins.
		{
			q.push(g[x][i]);                                                    // Bætum þeim í biðröðina.
			d[g[x][i]] = d[x] + 1;                                              //   og merkjum þá 'séða'.
		}
	}
	for (i = 0; i < n; i++) printf("d[%d] = %d\n", i, d[i]);                    // Prentum allar fjarlægðir.
	return 0;
}
