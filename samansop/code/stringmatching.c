#include <stdio.h>
#include <string.h>

int get_string(char *b, char t)
{ // Les inn i |b| streng af stadalinntaki fram að stafnum |t|.
	int i = 0, c = getchar();
	while (c != t && c != EOF) { b[i++] = c; c = getchar(); }
	b[i] = '\0';
	return i;
}

void bkmp(char *p, int *b)
{
	int i, j, m = strlen(p);
	for (i = 0, j = b[0] = -1; i < m; b[++i] = ++j)
		while (j >= 0 && p[i] != p[j]) j = b[j];
}

void kmp(char *s, char *p, int *r)
{
	int i, j, n = strlen(s), m = strlen(p), b[m + 1];
	bkmp(p, b);
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
	int i, n, m;
	m = get_string(p, 10), n = get_string(s, 10);
	while (n)
	{
		int r[n];
		kmp(s, p, r);
		for (i = 0; i < n; i++) if (r[i]) printf("%d ", i); printf("\n");
		m = get_string(p, 10), n = get_string(s, 10);
	}
	return 0;
}
