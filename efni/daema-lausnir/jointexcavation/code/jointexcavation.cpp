#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
int s[MAXN], n, sn = 0, v[MAXN], t[2];

void set_color(int x, int c)
{
	int i;
	if (v[x] == 0) t[0]--;                                                      // Uppfærum talningu rauðra hnúta.
	v[x] = c;                                                                   // Litum hnútinn.
	if (v[x] == 2) t[1]++;                                                      // Uppfærum talningu grænna hnúta.
	if (t[0] != t[1]) return;                                                   // Við erum ekki með jafnmarga græna og rauða hnúta, svo við höldum áfram.
	printf("%d %d\n", sn, t[0]);                                                // Prentum svarið.
	for (i = 0; i < sn; i++) printf("%d ", s[i] + 1); printf("\n");
	for (i = 0; i < n; i++) if (v[i] == 0) printf("%d ", i + 1); printf("\n");
	for (i = 0; i < n; i++) if (v[i] == 2) printf("%d ", i + 1); printf("\n");
	exit(0);                                                                    // Hættum keyrslu forritsins því við erum búin að finna svarið.
}

void dfs(vvi& g, int x)
{
	int i;
	s[sn++] = x, set_color(x, 1);                                               // Setjum x á hlaðann og litum x bláann.
	for (i = 0; i < g[x].size(); i++) if (v[g[x][i]] == 0)                      // Ítrum í gegnum rauðu (óheimsóttu) nágranna x.
		dfs(g, g[x][i]);                                                        // Höldum leitinni áfram í hnút g[x][i].
	sn--, set_color(x, 2);                                                      // Tökum x af hlaðanum og litum x grænan.
}

int main()
{
	int i, j, m, x, y;
	cin >> n >> m;                                                              // Innlestur hefst.
	vvi g(n);
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		x--, y--;
		g[x].push_back(y);
		g[y].push_back(x);                                                      // Innlestri lokið.
	}
	for (i = 0; i < n; i++) v[i] = 0;                                           // Litum alla hnúta rauða.
	t[0] = n, t[1] = 0;                                                         // Upphafstillum fjölda rauðra hnúta og fjölda grænna hnúta.
	dfs(g, 0);                                                                  // Hefjum leitina.
	return 0;
}
