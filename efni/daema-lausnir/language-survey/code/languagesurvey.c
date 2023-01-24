#include <stdio.h>
#include <assert.h>

int r[3][1000];
int sertilfelli(int* a, int n)
{
    int i, j, b[3][n], c[3] = {0, 0, 0};
	for (i = 0; i < n; i++) for (j = 0; j < 3; j++) b[j][i] = 0;
    i = 0;
    while (i < n && a[i] == 1) b[0][i++] = 1, c[0]++;                           // Látum A þangað til það kemur reitur með mörgum tungumálum.
    while (i < n && a[i] == 2) b[0][i] = 1, b[1][i] = 1, i++, c[0]++, c[1]++;   // Látum A og B þangað til það kemur reitur með einu tungumáli.
    while (i < n && a[i] == 1) b[1][i++] = 1, c[1]++;                           // Látum B þangað til það kemur reitur með mörgum tungumálum.
    while (i < n && a[i] == 2) b[1][i] = 1, b[2][i] = 1, i++, c[1]++, c[2]++;   // Látum B og C þangað til það kemur reitur með einu tungumáli.
    while (i < n && a[i] == 1) b[2][i++] = 1, c[2]++;                           // Látum C þangað til það kemur reitur með mörgum tungumálum.
	if (i < n) return 0;
    if (c[2] == 0 && c[1] == 0)                                                 // Afgreiðu tilvikið þegar bara eitt tungumál er notað.
    {
        if (n == 2) return 0;
        b[1][0] = b[2][1] = 1;
        b[0][0] = b[0][1] = 0;
    }
    else if (c[2] == 0)                                                         // Afgreiðum tilvikið þegar bara tvö tungumál eru notuð.
    {
        for (i = 0; i < n; i++) if (a[i] == 2) break;
        b[2][i] = 1;
    }
    for (j = 0; j < 3; j++) for (i = 0; i < n; i++)                             // Látum svarið í fylki til að prenta á eftir.
		r[j][i] = b[j][i] ? 'A' + j : '.';
    return 1;
}

int main()
{
    int i, j, x, y, z[2], n, m, g[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
	scanf("%d%d", &n, &m); getchar();                                           // Innlestur hefst.
    int a[n][m], b[n][m], c[n][m];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++) a[i][j] = getchar() - '0';
		getchar();                                                              // Innlestri lokið.
	}
    if (n == 1 && m == 1)                                                       // Sértilfellið 1.
    {
        if (a[0][0] == 1) { printf("impossible\n"); return 0; }                 // Öll tungumál þurfa að vera töluð.
        printf("A\n\nB\n\nC\n");
        return 0;
    }
    if (n == 1)                                                                 // Sértilfelli 2A.
    {
        int g[m];
		for (i = 0; i < m; i++) g[i] = a[0][i];
        if (!sertilfelli(g, m)) { printf("impossible\n"); return 0; }           // Reiknum gráðugt fyrir sértilfellið.
        for (x = 0; x < 3; x++)                                                 // Prentum svarið.
		{
			for (i = 0; i < m; i++) printf("%c", r[x][i]);
			printf("\n\n");
		}
        return 0;
    }
    if (m == 1)                                                                 // Sértilfelli 2B.
    {
        int g[n];
        for (i = 0; i < n; i++) g[i] = a[i][0];
        if (!sertilfelli(g, n)) { printf("impossible\n"); return 0; }           // Reiknum gráðugt fyrir sértilfellið.
		for (x = 0; x < 3; x++)                                                 // Prentum svarið.
		{
			for (i = 0; i < n; i++) printf("%c\n", r[x][i]);
			printf("\n");
		}
        return 0;
    }
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) b[i][j] = 1;                // Byrjum að setja B allstaðar í grunnskiptinguna.
    for (i = 0; i < n; i++) b[i][0] = 2;                                        // Setjum A í fyrsta dálk grunnskiptingunnar.
    z[0] = n - 1, z[1] = m - 3, x = n, y = m - 1;
    for (j = 0; z[j%2] > 0; z[j%2] -= 2, j++) for (i = 0; i < z[j%2]; i++)      // Setjum C í grunnskiptinguna á viðeigandi stað (sjá glærur).
			b[x += g[j%4][0]][y += g[j%4][1]] = 0;                              // Förum z[j%2] skref í stefnu g[j%4], sem myndir spíral.
	for (i = 0; i < n; i++) for (j = 0; j < m; j++) c[i][j] = -1;               // Upphafstillum fylkið sem geymir öðruvísi nágrannann.
	for (i = 0; i < n; i++) for (j = 0; j < m; j++)                             // Finnum, fyrir hvern reit, nágranna sem er öðruvísi.
    {
        if (i > 0 && b[i - 1][j] != b[i][j]) c[i][j] = b[i - 1][j];
        if (j > 0 && b[i][j - 1] != b[i][j]) c[i][j] = b[i][j - 1];
        if (i < n - 1 && b[i + 1][j] != b[i][j]) c[i][j] = b[i + 1][j];
        if (j < m - 1 && b[i][j + 1] != b[i][j]) c[i][j] = b[i][j + 1];
    }
	for (x = 0; x < 3; x++)                                                     // Prentum svarið.
    {
		for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++) printf("%c",
					(b[i][j] == x || (a[i][j] == 2 && c[i][j] == x))            // Skoðum hvort reiturinn sé í grunnskiptingunni eða sé reitur hefur
					? 'A' + x : '.');                                           //    mörg tungumál og finnum þá ólíkan nágranna.
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}


