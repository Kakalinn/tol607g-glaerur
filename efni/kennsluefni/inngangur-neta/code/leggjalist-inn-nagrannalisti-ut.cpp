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
	for (i = 0; i < n; i++)                                                     // Prentum nágranna hvers hnúts.
	{
		printf("%d: ", i + 1);                                                  // Prentum hnútinn.
		for (j = 0; j < g[i].size(); j++) printf("%d ", g[i][j] + 1);           // Prentum nágranna hnúts i á einni línu.
		printf("\n");
	}
	return 0;
}
