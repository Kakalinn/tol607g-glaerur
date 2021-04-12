#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int get_string(char* b, char t)
{ // Les inn i |b| streng af stadalinntaki fram að stafnum |t|.
	int i = 0, c = getchar();
	while (c != t) { b[i++] = c; c = getchar(); }
	b[i] = '\0';
	return i;
}

void bkmp(char* p, int* b, int m)
{
	int i = 0, j = -1;
	b[0] = -1;
	while (i < m)
	{
		while (j >= 0 && p[i] != p[j]) j = b[j];
		b[i++] = j++;
	}
}

void kmp(char* s, int n, char* p, int m, int* b)
{
	int i = 0, j = 0;
	while (i < n)
	{
		while (j >= 0 && s[i] != p[j]) j = b[j];
		i++, j++;
		if (j == m) printf("%d\n", i - j), j = b[j];
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
	int b[m];
	bkmp(p, b, m);
	rep(i, m) printf("%4d ", b[i]); printf("\n");
	rep(i, m) printf("   %c ", p[i]); printf("\n");
	kmp(s, n, p, m, b);
	return 0;
}
