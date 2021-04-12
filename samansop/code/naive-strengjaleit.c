void naive(char* s, int n, char* p, int m)
{
	int i, j;
	rep(i, n - m + 1)
	{
		rep(j, m) if (s[i + j] != p[j]) break;
		if (j >= m) printf("%d ", i - j);
	}
	printf("\n");
}
