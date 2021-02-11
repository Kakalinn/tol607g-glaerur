int main()
{
	int n, m, i, x, y, z;
	scanf("%d%d", &n, &m);
	int a[n], p[4*n + 1];
	for (i = 0; i < n; i++) scanf("%d", &(a[i]));
	for (i = 0; i < 4*n + 1; i++) p[i] = 0;
	for (i = 0; i < n; i++) update(p, 0, n - 1, i, a[i], 1);
	while (m-- != 0)
	{
		scanf("%d%d%d", &x, &y, &z);
		if (x == 1) update(p, 0, n - 1, y, z, 1);
		if (x == 2) printf("%d\n", query(p, 0, n - 1, y, z, 1));
	}

	return 0;
}
