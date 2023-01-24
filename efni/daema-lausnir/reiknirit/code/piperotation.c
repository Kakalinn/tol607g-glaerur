#include <stdlib.h>
#include <stdio.h>

void imp()
{
	printf("Impossible\n");
	exit(0);
}

int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);
	char s[n][m + 1], a[n + 1][m + 1], b[n + 1][m + 1];
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++)
		a[i][j] = b[i][j] = 0;
	for (i = 0; i < n; i++) scanf("%s", s[i]);
	for (i = 0; i < n; i++) for (j = 0; j < m; j++)
	{
		if (a[i][j] == 0 && b[i][j] == 0)
		{
			if (s[i][j] == 'C') a[i + 1][j]++, b[i][j + 1]++;
			else if (s[i][j] != 'A') imp();
		}
		else if (a[i][j] == 1 && b[i][j] == 0)
		{
			if (s[i][j] == 'B') a[i + 1][j]++;
			else if (s[i][j] == 'C') b[i][j + 1]++;
			else imp();
		}
		else if (a[i][j] == 0 && b[i][j] == 1)
		{
			if (s[i][j] == 'B') b[i][j + 1]++;
			else if (s[i][j] == 'C') a[i + 1][j]++;
			else imp();
		}
		else
		{
			if (s[i][j] == 'D') a[i + 1][j]++, b[i][j + 1]++;
			else if (s[i][j] != 'C') imp();
		}
	}
	for (i = 0; i < n; i++) if (b[i][m]) imp();
	for (i = 0; i < m; i++) if (a[n][i]) imp();
	printf("Possible\n");
	return 0;
}
