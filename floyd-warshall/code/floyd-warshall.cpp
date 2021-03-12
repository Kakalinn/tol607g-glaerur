vvi floydwarshall(vvii& g)
{
	int i, j, k, n = g.size();
	vvi dp(n, vi(n, INF));
	rep(i, n) dp[i][i] = 0;
	rep(i, n) rep(j, g[i].size())
		dp[i][g[i][j].first] = min(g[i][j].second, dp[i][g[i][j].first]);
	rep(k, n) rep(i, n) rep(j, n)
	{
		if(dp[i][k] == INF || dp[k][j] == INF) continue;
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	}
	rep(k, n) rep(i, n) rep(j, n)
	{
		if(dp[i][k] == INF || dp[k][j] == INF || dp[i][j] == INF) continue;
		if(dp[i][k] + dp[k][j] < dp[i][j]) dp[i][j] = -INF;
	}
	return dp;
}
