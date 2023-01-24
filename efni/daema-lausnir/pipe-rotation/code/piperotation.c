#include <stdlib.h>
#include <stdio.h>

void imp()                                                                      // Fall sem prentar 'Impossible' og hættir keyrslu.
{
	printf("Impossible\n");
	exit(0);
}

int main()
{
	int i, j, n, m;
	scanf("%d%d", &n, &m);                                                      // Innlestur hefst.
	char s[n][m + 1], a[n + 1][m + 1], b[n + 1][m + 1];
	for (i = 0; i < n + 1; i++) for (j = 0; j < m + 1; j++)
		a[i][j] = b[i][j] = 0;
	for (i = 0; i < n; i++) scanf("%s", s[i]);                                  // Innlestru lokið.
	for (i = 0; i < n; i++) for (j = 0; j < m; j++)                             // Ítrum í gegnum borðið til vinstri og niður. Þá er alltaf búið að
	{                                                                           //    ákvarða reitinn fyrir ofan og neðan. Það dugar til að ákvarða
		if (a[i][j] == 0 && b[i][j] == 0)                                       //    tiltekinn reit (sjá glærur).
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
	for (i = 0; i < n; i++) if (b[i][m]) imp();                                 // Skoðum hvort eitthvað snúi út.
	for (i = 0; i < m; i++) if (a[n][i]) imp();                                 // Skoðum hvort eitthvað snúi út.
	printf("Possible\n");                                                       // Ekkert hefur mistekist hingað til, svo svarið er 'Possible'.
	return 0;
}
