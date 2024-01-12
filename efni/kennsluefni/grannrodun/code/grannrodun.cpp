#include <bits/stdc++.h>                                                        // Fyrsta lína inntaksins eru tvær heiltölur,
using namespace std;                                                            //   fjöldi hnúta og fjöldi leggja.
typedef vector<int> vi;                                                         // Síðan koma m línur sem svara til leggjalistans.
typedef vector<vi> vvi;

int tsort(vvi& g, vi& t)
{
    int i, j, r = 1, n = g.size();
    vi d(n, 0);                                                                 // Upphafstillum innstigin sem 0.
    t.clear();                                                                  // Tæmum t til að geyma grannröðunina.
    int q[n], qe = 0, qs = 0;                                                   // Upphafstillum tóma biðröð.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++) d[g[i][j]]++;     // Reiknum innstig hnútanna.
    for (i = 0; i < n; i++) if (d[i] == 0) q[qe++] = i;                         // Setjum all hnnútanna með innstig 0 í biðröðina.
    while (qe != qs)
    {
        if (qe - qs > 1) r = 2;                                                 // Ef biðröðin inniheldur fleiri en einn hnút getur grannröðunin ekki
        int k = q[qs++];                                                        //   verið ótvírætt ákvörðuð.
        t.push_back(k);                                                         // Bætum tilteknum hnút í grannröðunina.
        for (i = 0; i < g[k].size(); i++) if (--d[g[k][i]] == 0)                // Fjarlægjum hnútinn úr netinu. Þetta minnkar innstig nágrannanna. Ef
            q[qe++] = g[k][i];                                                  //   nýja innstig nágrannanna verður 0 bætum við þeim í biðröðina.
    }
    return t.size() != n ? 0 : r;                                               // Skilum 0 ef netið er ekki órásað, 1 ef grannröðunin er ótvírætt
}                                                                               //   ákvörðuð eða 2 ef hún er ekki ótvírætt ákvörðuð.

int main()
{
    int i, j, n, m, c = 0;
    cin >> n >> m;
    vi t;
    vvi g(n);
    for (i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
    }
    int r = tsort(g, t);
    if (!r) { printf("Netið er ekki órásað.\n"); return 0; }
    printf("Grannröðunin er %sótvírætt ákvörðuð.\n", r == 2 ? "ekki " : "");
    for (i = 0; i < n; i++) printf("%d ", t[i] + 1); printf("\n");
    return 0;
}
