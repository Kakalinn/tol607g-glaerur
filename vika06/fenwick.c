#include <stdio.h>

int get_int()
{
	int ret = 0;
	char c  = getchar();
	int sgn;

	while (1)
	{
		if (c == EOF)
		{
			return EOF;
		}
		if (c >= '0' && c <= '9')
		{
			sgn = 1;
			break;
		}
		if (c == '-')
		{
			c = getchar();

			if (c < '0' || c > '9')
			{
				continue;
			}

			sgn = -1;
			break;
		}
		c = getchar();
	}

	while (1)
	{
		ret = ret*10 + c - '0';

		c = getchar();

		if (c < '0' || c > '9')
		{
			return sgn*ret;
		}
	}
}

#define LSB(i) ((i) & -(i))

int sum(int* a, int i)
{
	int sum = 0;
	while (i > 0) 
	{
		sum = sum + a[i];
		i = i - LSB(i);
	}
	return sum;
}

void add(int* a, int n, int i, int k)
{
	while (i < n) 
	{
		a[i] = a[i] + k;
		i = i + LSB(i);
	}
}

int main()
{
	int i;
	int n = get_int() + 1;
	int a[n];
	int b[16] = {-1, 1, 2, 3, 1, 2, 3, 3, 2, 1, 2, 2, 2, 5, 1, 1};
	for (i = 1; i < n; i++)
	{
		a[i] = 0;
	}
	for (i = 1; i < n; i++)
	{
		add(a, 16, i, b[i]);
	}
	for (i = 1; i < n; i++)
	{
		printf(">> %d\n", b[i]);
	}

	add(a, n, 1, i);

	printf("%d\n", sum(a, 1));
	printf("%d\n", sum(a, 2));
	printf("%d\n", sum(a, 3));
	printf("%d\n", sum(a, 4));
	printf("%d\n", sum(a, 5));

	for (i = 1; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}
