#include <stdio.h>

int get_string(char* b, char t)
{
	int i = 0, c = getchar();
	while (c != t)
	{
		b[i++] = c; c = getchar();
	}
	b[i] = '\0';
	return i;
}
void _kmp(char* p, int* b, int m)
{
	int i = 0, j = -1; b[0] = -1;
	while (i < m)
	{
		while (j >= 0 && p[i] != p[j])
		{
			j = b[j];
		}
		i++; j++; b[i] = j;
	}
}
void kmp(char* s, int n, char* p, int m, int* b)
{
	int i = 0, j = 0;
	while (i < n)
	{
		while (j >= 0 && s[i] != p[j])
		{
			j = b[j];
		}
		i++; j++;
		if (j == m)
		{
			printf("%d\n", i - j); j = b[j];
		}
	}
}
int main()
{
	char s[1000001], p[1001];
	int i;
	printf("Langi strengur: "); fflush(stdout);
	int n = get_string(s, 10);
	printf("Stutti strengur: "); fflush(stdout);
	int m = get_string(p, 10);
	int b[m];
	_kmp(p, b, m);
	for (i = 0; i < m; i++) printf("%4d ", b[i]); printf("\n");
	for (i = 0; i < m; i++) printf("   %c ", p[i]); printf("\n");
	kmp(s, n, p, m, b);
}
