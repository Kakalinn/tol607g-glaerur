vvi floyd_warshall(vvii& g)
{
    int i, j, k, n = g.size();
    vvi d(n, vi(n, INF));                                                       // Upphafstillum tvívíða minnistöflu með mjög stórri tölu.
    for (i = 0; i < n; i++) d[i][i] = 0;                                        // Lögum upphafsgildin á hornalínunni.
    for (i = 0; i < n; i++) for (j = 0; j < g[i].size(); j++)                   // Ítrum í gegnum alla leggi netsins.
        d[i][g[i][j].first] = min(g[i][j].second, d[i][g[i][j].first]);         // Breytum nágrannalistunum í g í nágranna fylkið d.
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum í gegnum allar stöðurnar.
    {
        if (d[i][k] == INF || d[k][j] == INF) continue;                         // Getum ekki bætt ef gildið sem við erum í er óendalegt.
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);                              // Uppfærum ef þörf er á.
    }
    for (k = 0; k < n; k++) for (i = 0; i < n; i++) for (j = 0; j < n; j++)     // Ítrum aftur í gegnum allar stöðurnar til að finna áhrif neikvæðra rása.
    {
        if (d[i][k] == INF || d[k][j] == INF || d[i][j] == INF) continue;       // Getum ekki bætt ef gildið sem við erum í er óendanlegt.
        if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = -INF;                        // Ef við getum bætt er neikvæð rás á leiðinni.
    }
    return d;                                                                   // Skilum fjarlægðunum milli allra hnútanna.
}
