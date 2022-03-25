vvi floydwarshall(vvii& g)
{
	int i, j, k, n = g.size();
	vvi d(n, vi(n, INF));
	rep(i, n) d[i][i] = 0;
	rep(i, n) rep(j, g[i].size())
		d[i][g[i][j].first] = min(g[i][j].second, d[i][g[i][j].first]);
	rep(k, n) rep(i, n) rep(j, n)
	{
		if (d[i][k] == INF || d[k][j] == INF) continue;
		d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}
	rep(k, n) rep(i, n) rep(j, n)
	{
		if (d[i][k] == INF || d[k][j] == INF || d[i][j] == INF) continue;
		if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = -INF;
	}
	return d;
}
