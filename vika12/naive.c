#include <stdio.h>
#include "battis.h"

void naive(char* s, int n, char* p, int m)
{
	int i, j;
	for (i = 0; i < n - m + 1; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (s[i + j] != p[j])
			{
				break;
			}
		}
		if (j >= m)
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main()
{
	char s[1000001], p[1001];
	int n = battis_read_string(s, 10);
	int m = battis_read_string(p, 10);
	naive(s, n, p, m);
}
