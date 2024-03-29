#include <bits/stdc++.h>
#define MAXN 200000
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

int dfs(vvi &g, int u, int d, int *s, int *a, int *l)                           // d svarar til u_{num}.
{
    l[u] = d, s[++s[0]] = u;                                                    // Upphafsstillum l og setjum u á hlaðann.
    int i, x, z = d;
    for (i = 0; i < g[u].size(); i++)                                           // Ítrum í gegnum alla nágranna u.
    {
        x = g[u][i];
        if (l[x] == -1) d = dfs(g, x, d + 1, s, a, l);                          // Heimsækjum nágrannann.
        if (a[x] == -1) l[u] = min(l[u], l[x]);                                 // Uppfærum frá nágrannanum ef hann er ekki úr fyrri umferð.
    }
    if (l[u] == z) while (a[u] == -1) a[s[s[0]--]] = u;                         // Nýr samhengisþáttur. Merkjum hnútana í honum.
    return d;
}

void scc(vvi &g, int *a)
{
    int i, n = g.size(), s[n + 1], l[n];                                        // l[u] svarar til u_{low}.
    for (i = 0, s[0] = 0; i < n; i++) l[i] = a[i] = -1;                         // Upphafstillum a og l með -1.
    for (i = 0; i < n; i++) if (l[i] == -1) dfs(g, i, 0, s, a, l);              // Leitum með dýptarleit í öllu netinu.
}

// Hæg útfærsla til að bera saman
#define LOWN 400
int ans[LOWN][LOWN], w[LOWN];
int dfs_slow(vvi &g, int x, int t)
{
    int i;
    if (x == t) return 1;
    w[x] = 1;
    for (i = 0; i < g[x].size(); i++) if (!w[g[x][i]] && dfs_slow(g, g[x][i], t)) return 1;
    return 0;
}

void slow(vvi &g)
{
    int n = g.size(), i, j, k, x, y;
    assert(n <= LOWN);
    for (i = 0; i < n; i++) for (j = 0; j <= i; j++) 
    {
        for (k = 0; k < n; k++) w[k] = 0;
        x = dfs_slow(g, i, j);
        for (k = 0; k < n; k++) w[k] = 0;
        y = dfs_slow(g, j, i);
        ans[i][j] = ans[j][i] = (x == 1 && y == 1);
    }
}

void compare(vvi &d, int n, int m)
{
    int i, j, a[n];
    vvi g(n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) if (d[i][j])
        g[i].push_back(j);
    slow(g);
    scc(g, a);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        assert(ans[i][j] && a[i] == a[j] || !ans[i][j] && a[i] != a[j]);
}

int main()
{
    srand(time(NULL));
    int i, j, n = 100, m = 300, q = -1, x, y;
    vvi d(n, vi(n));
    j = 0;
    printf("generating graph\n");
    while (j < m)
    {
        x = rand()%n, y = rand()%n;
        if (x == y || d[x][y]) continue;
        d[x][y] = 1;
        j++;
    }
    printf("graph generated\n");
    while (q--)
    {
        compare(d, n, m);
        x = rand()%n, y = rand()%n;
        while (x == y || !d[x][y]) x = rand()%n, y = rand()%n;
        d[x][y] = 0;
        x = rand()%n, y = rand()%n;
        while (x == y || d[x][y]) x = rand()%n, y = rand()%n;
        d[x][y] = 1;
        printf("test passed %d\n", q < 0 ? -q : q);
    }
    return 0;
}
