#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef pair<int, int> ii;                                                      // Síðan koma m línur sem svara til leggjalistans, með vigtum.
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{
	int i, j, n, m, x, y, w;
	cin >> n >> m;                                                              // Lesum inn fjölda hnúta og fjölda leggja.
	vvii g(n);
	for (i = 0; i < m; i++)                                                     // Lesum inn leggina.
	{
		cin >> x >> y >> w;                                                     // Tiltekinn leggur frá x til y með bigt w.
		x--, y--;                                                               // Algengt er að hnútar séu 1, ..., n, en við viljum 0, ..., n - 1.
		g[x].push_back(ii(y, w));                                               // Bætum við legg frá x til y með vigt w.
		g[y].push_back(ii(x, w));                                               // Ef netið er óstefnt þarf að bæta við eins legg frá y to x, annars ekki.
	}
	printf("Nágrannar:\n");
	for (i = 0; i < n; i++)                                                     // Prentum nágranna hvers hnúts.
	{
		printf("%d: ", i + 1);                                                  // Prentum hnútinn.
		for (j = 0; j < g[i].size(); j++) printf("%2d ", g[i][j].first + 1);    // Prentum nágranna hnúts i á einni línu.
		printf("\n");
	}
	printf("Vigtir:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d: ", i + 1);                                                  // Prentum hnútinn.
		for (j = 0; j < g[i].size(); j++) printf("%2d ", g[i][j].second);       // Prentum vigtirnar á leggjum sem voru prentaðir á undan.
		printf("\n");
	}
	return 0;
}
