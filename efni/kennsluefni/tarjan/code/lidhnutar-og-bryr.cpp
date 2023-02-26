#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define MAXN 200000

int a[MAXN], v[MAXN], curnum;                                                   // v[u] svara til u_{num} á glærunum.
vi cp; vii bri;
int dfs(const vvi &g, int u, int p, int d)
{
	int i, x, c = 0, z = d, y; v[u] = d;                                        // z svarar til u_{low} og y svara til v_{low}.
	for (i = 0; i < g[u].size(); i++) if (g[u][i] != p)                         // Ítrum í gegnum alla nágranna u nema þann sem við komum frá.
	{
		x = g[u][i];                                                            // x er nágranni u.
		if (v[x] == -1)
		{
			y = dfs(g, x, u, d + 1), c++;                                       // Heimsækjum x og lögum teljarann.
			z = min(z, y);                                                      // Uppfærum z ef þörf er á.
			if (y > v[u]) bri.push_back(ii(u, x));                              // Brú fundin, sjá glærur.
			if (p != -1 && y >= v[u]) a[u] = 1;                                 // Liðhnútur fundinn, sjá glærur.
		}
		else z = min(z, v[x]);                                                  // Það er búið að heimækja v, svo við gætum þurft að uppfæra z.
	}
	if (p == -1 && c > 1) a[u] = 1;                                             // Sértilfelli fyrir upphafshnútinn.
	return z;
}

void cpb(const vvi &g)
{
	cp.clear(), bri.clear();                                                    // Tæmum fyrri svör ef á er þörf.
	for (int i = 0; i < g.size(); i++) v[i] = -1, a[i] = 0;                     // Upphafstillum v með -1.
	for (int i = 0; i < g.size(); i++) if (v[i] == -1) dfs(g, i, -1, 0);        // Framkvæmum dýptarleitina fyrir hvern samhengisþátt.
	for (int i = 0; i < g.size(); i++) if (a[i]) cp.push_back(i);               // Setjum liðhnútana í cp.
}

// Hæg útfærsla til að bera saman
int uf_find(int *p, int x)                                                      // Finnur ráðherra flokksins sem x tilheyrir.
{
	return p[x] < 0 ? x : (p[x] = uf_find(p, p[x]));                            // Skilar ráðherranum ef hann er fundinn. Þjappar annars keðjuna.
}

void uf_join(int *p, int x, int y)                                              // Sameinar flokkana sem x og y tilheyra.
{
	int rx = uf_find(p, x), ry = uf_find(p, y);                                 // Finnum ráðherra hvors flokks.
	if (rx == ry) return;                                                       // Ef x og y eru í sama flokknum þarf ekkert að gera.
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;                              // Ef keðjan undir rx inniheldur færri stök verður rx nýi ráðherrann.
	else p[rx] += p[ry], p[ry] = rx;                                            // Ef keðjan undir ry inniheldur færri stök verður ry nýi ráðherrann.
}

void uf_init(int *p, int n)                                                     // Upphafstillir keðjurnar sem eru minni en n.
{
	for (int i = 0; i < n; i++) p[i] = -1;
}

int cc_cnt(int *x, int *y, int v, int e, int n, int m)
{
	int i, p[n], c[n], r = 0;
	uf_init(p, n);
	for (i = 0; i < n; i++) c[i] = 0;
	for (i = 0; i < m; i++)
	{
		if (i == e) continue;
		if (x[i] == v || y[i] == v) continue;
		uf_join(p, x[i], y[i]);
	}
	for (i = 0; i < n; i++) c[uf_find(p, i)] = 1;
	for (i = 0; i < n; i++) if (i != v) r += c[i];
	return r;
}

vi cp_correct; vii bri_correct;
void slow(int *x, int *y, int n, int m)
{
	int i, c = cc_cnt(x, y, -1, -1, n, m);
	//printf("ccccc = %d\n", cc_cnt(x, y, -1, -1, n, m));
	//printf("ccccc = %d\n", cc_cnt(x, y, -1, 0, n, m));
	cp_correct.clear(), bri_correct.clear();
	//for (i = 0; i < cp_correct.size(); i++) printf(">> this sohuld def not print >> %d\n", cp_correct[i]);
	for (i = 0; i < n; i++) if (c < cc_cnt(x, y, i, -1, n, m)) cp_correct.push_back(i);
	for (i = 0; i < m; i++) if (c < cc_cnt(x, y, -1, i, n, m)) bri_correct.push_back(ii(x[i], y[i]));
}

void compare(vvi &d, int n, int m)
{
	int i, j, x[m], y[m], k = 0;
	vvi g(n);
	for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (d[i][j])
	{
		g[i].push_back(j);
		if (i < j) x[k] = i, y[k] = j, k++;
	}
	//printf("edges:\n");
	//for (i = 0; i < m; i++) printf("  %d %d\n", x[i], y[i]);
	assert(k == m);
	printf("running test...\n");
	slow(x, y, n, m);
	cpb(g);
	//printf(">>>>>> %d %d, %d %d\n", bri.size(), cp.size(), bri_correct.size(), cp_correct.size());
	for (i = 0; i < bri.size(); i++) if (bri[i].first > bri[i].second) swap(bri[i].first, bri[i].second);
	sort(bri.begin(), bri.end());
	sort(bri_correct.begin(), bri_correct.end());
	sort(cp.begin(), cp.end());
	sort(cp_correct.begin(), cp_correct.end());
	//for (i = 0; i < cp.size(); i++) printf(">> >> %d\n", cp[i]); printf("\n");
	//for (i = 0; i < cp_correct.size(); i++) printf(">> >> %d\n", cp_correct[i]); printf("\n");
	//for (i = 0; i < bri.size(); i++) printf(">> >> %d %d\n", bri[i].first, bri[i].second); printf("\n");
	//for (i = 0; i < bri_correct.size(); i++) printf(">> >> %d %d\n", bri_correct[i].first, bri_correct[i].second); printf("\n");
	assert(bri.size() == bri_correct.size());
	assert(cp.size() == cp_correct.size());
	for (i = 0; i < bri.size(); i++) assert(bri[i] == bri_correct[i]);
	for (i = 0; i < cp.size(); i++) assert(cp[i] == cp_correct[i]);
	//printf(">>>>>> %d %d\n", bri.size(), cp.size());
}



int main()
{
	srand(time(NULL));
	//srand(11);
	int i, j, n = 100, m = 100, q = -1, x, y;
	vvi d(n, vi(n));
	j = 0;
	printf("generating graph\n");
	while (j < m)
	{
		x = rand()%n, y = rand()%n;
		if (x == y || d[x][y]) continue;
		d[y][x] = d[x][y] = 1;
		j++;
	}
	printf("graph generated\n");
	while (q--)
	{
		compare(d, n, m);
		x = rand()%n, y = rand()%n;
		while (x == y || !d[x][y]) x = rand()%n, y = rand()%n;
		d[y][x] = d[x][y] = 0;
		x = rand()%n, y = rand()%n;
		while (x == y || d[x][y]) x = rand()%n, y = rand()%n;
		d[y][x] = d[x][y] = 1;
		printf("test passed %d\n", q);
	}
	return 0;
}
