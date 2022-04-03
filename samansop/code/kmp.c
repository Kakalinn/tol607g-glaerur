#include <stdio.h>
#include <string.h>

int get_string(char *b, char t)
{ // Les inn i |b| streng af stadalinntaki fram að stafnum |t|.
	int i = 0, c = getchar();
	while (c != t) { b[i++] = c; c = getchar(); }
	b[i] = '\0';
	return i;
}

void prefix_function(char *p, int *b)
{ // Reiknar forstrengsfall p og geymir gildin í b.
	int i, j, m = strlen(p);
	for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
		while (j >= 0 && p[i] != p[j]) j = b[j];
}

void kmp(char *s, char *p, int *r)
{ // r[i] segir hvort i-ta hlutstrengur s sé sá sami og p.
	int i, j, n = strlen(s), m = strlen(p), b[m + 1];
	prefix_function(p, b);
	for (i = 0; i < n; i++) r[i] = 0;
	for (i = j = 0; i < n; )
	{
		while (j >= 0 && s[i] != p[j]) j = b[j];
		i++, j++;
		if (j == m) r[i - j] = 1, j = b[j];
	}
}

int main()
{
	char s[1000001], p[1000001];
	int i;
	printf("Langi strengur: "); fflush(stdout);
	int n = get_string(s, 10);
	printf("Stutti strengur: "); fflush(stdout);
	int m = get_string(p, 10);
	int b[m + 1], r[n];
	prefix_function(p, b);
	for (i = 0; i <= m; i++) printf("%4d ", b[i]); printf("\n");
	for (i = 0; i < m; i++) printf("   %c ", p[i]); printf("\n");
	kmp(s, p, r);
	printf("%s\n", s);
	for (i = 0; i < n; i++) printf("%c", r[i] ? 'x' : ' ');
	printf("\n");
	return 0;
}
