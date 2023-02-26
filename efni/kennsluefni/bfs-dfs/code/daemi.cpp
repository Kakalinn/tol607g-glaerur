#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

int isin(int x, int y, int r, int c)                                            // Er (x, y) innan rammans?
{
	if (x >= r || x < 0 || y >= c || y < 0) return 0;
	return 1;
}

int main()
{
	int i, j, r, c, x, y, g[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};         // Fylkið g geymir skrefin sem við megum taka.
	cin >> r >> c;                                                              // Innlestur hafinn.
	string a[r];
	for (i = 0; i < r; i++) cin >> a[i];                                        // Innlestri lokið.
	for (i = 0; i < r; i++) for (j = 0; j < c; j++) if (a[i][j] == 'O')         // Finnum upphafsreitinn á myndinni.
		x = i, y = j;
	int d[r][c];
	for (i = 0; i < r; i++) for (j = 0; j < c; j++) d[i][j] = -1;               // Upphafstillum alla hnútana sem 'óséða'.
	queue<ii> q;
	q.push(ii(x, y)), d[x][y] = 0;                                              // Setjum upphafstöðun í biðröð og merkjum hana 'séða'.
	while (q.size() > 0)                                                        // Hættum ekki fyrr en biðröðin er tóm, þ.e. allir hnútar 'kláraðir'.
	{
		ii p = q.front(); q.pop();                                              // Veljum fresta hnútinn í biðröðinni og fjarlægjum hann.
		x = p.first, y = p.second;
		for (i = 0; i < 4; i++)                                                 // Ítrum í gegnum öll skrefin sem við megum taka.
		{
			int xx = x + g[i][0], yy = y + g[i][1];                             // Reiknum hvar við endum eftir að taka skrefið.
			if (a[xx][yy] == 'X' || !isin(xx, yy, r, c) || d[xx][yy] != -1)     // Gáum hvort við klessum á vegg, göngum útaf eða hnúturinn sé 'séður'.
				continue;
			q.push(ii(xx, yy)), d[xx][yy] = d[x][y] + 1;                        // Bætum hnútnum í biðröðina og merkjum hann 'séðan'.
		}
	}
	for (i = 0; i < r; i++)                                                     // Prentum svarið.
	{
		for (j = 0; j < c; j++)  printf("%2d ", d[i][j]);
		printf("\n");
	}
	return 0;
}
