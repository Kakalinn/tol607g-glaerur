#include <stdio.h>

void nge(int* a, int* b, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		b[i] = -1;
		for (j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
			{
				b[i] = j;
				break;
			}
		}
	}
}

int main()
{
	int i, n;
	printf("Staerd listans: "); fflush(stdin);
	scanf("%d", &n);
	int a[n], b[n];
	printf("%d tolur: ", n); fflush(stdin);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(a[i]));
	}
	nge(a, b, n);
	printf("NGE:\n");
	for (i = 0; i < n; i++)
	{
		printf("%8d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%8d ", (b[i] != -1 ? a[b[i]] : -1));
	}
	printf("\n");
}
