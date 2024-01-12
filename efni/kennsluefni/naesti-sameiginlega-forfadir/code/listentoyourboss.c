#include <stdio.h>
#define MAXN 100000
#define getchar() fgetc_unlocked(stdin)
#define rep(E, F) for (E = 0; E < (F); E++)
#define per(E, F) for (E = (F) - 1; E >= 0; E--)
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }

int get_int()
{
    int r = 0, c = getchar(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = getchar();
    while (c == '-') s *= -1, c = getchar();
    while (c >= '0' && c <= '9') r = r*10 + c - '0', c = getchar();
    return s*r;
}

int f[MAXN], s[MAXN], d[MAXN], h[MAXN], p[MAXN];

void hld_init(int n)
{
    int i, j, k = n, q[n], qs = 0, qe = 0, a[n];
    rep(i, n) s[i] = 1, h[i] = -1, f[i] = i, d[i] = 0;
    rep(i, n) if (i != 0) d[p[i]]++;
    rep(i, n) if (i != 0 && d[i] == 0) q[qe++] = a[--k] = i;
    for (i = q[qs++]; qs <= qe; i = q[qs++])
        if (--d[p[i]] == 0) q[qe++] = p[i], a[--k] = p[i];
    rep(i, n) d[i] = (i == 0 ? 0 : -1);
    rep(i, n) if (d[a[i]] == -1) d[a[i]] = d[p[a[i]]] + 1;                                       // Compute the depths.
    per(i, n) if (i != 0) s[p[a[i]]] += s[a[i]];                                                    // Compute the subtree sizes.
    rep(i, n) if (i != 0) h[p[i]] = i;                                                              // Assign some edges as heavy edges.
    rep(i, n) if (i != 0) h[p[i]] = s[h[p[i]]] < s[i] ? i : h[p[i]];                                // Determine the correct heavy edges.
    rep(i, n) if (h[a[i]] != -1) f[h[a[i]]] = f[a[i]];                                                                 // Assigning the heavy paths.
    //printf(" i: "); rep(i, n) printf("%2d ", i); printf("\n");
    //printf(" a: "); rep(i, n) printf("%2d ", a[i]); printf("\n");
    //printf(" s: "); rep(i, n) printf("%2d ", s[i]); printf("\n");
    //printf(" d: "); rep(i, n) printf("%2d ", d[i]); printf("\n");
    //printf(" p: "); rep(i, n) printf("%2d ", p[i]); printf("\n");
    //printf(" h: "); rep(i, n) printf("%2d ", h[i]); printf("\n");
    //printf(" f: "); rep(i, n) printf("%2d ", f[i]); printf("\n");
}

int hld_lca(int u, int v)
{
    while (f[u] != f[v])
    {
        //printf(">> %d %d | %d %d | %d %d\n", u, v, f[u], f[v], p[f[u]], p[f[v]]);
        if (d[f[u]] > d[f[v]]) u = p[f[u]];
        else v = p[f[v]];
    }
    return d[u] < d[v] ? u : v;
}

int main()
{
    int i, j, n = get_int(), m = get_int();
    rep(i, n) p[i] = (i == 0 ? 0 : get_int() - 1);
    hld_init(n);
    while (m--)
    {
        int x = get_int() - 1, y = get_int() - 1;
        printf("%s\n", hld_lca(x, y) == y ? "No" : "Yes");
    }
    return 0;
}

