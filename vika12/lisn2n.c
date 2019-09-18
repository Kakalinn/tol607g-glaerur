#include <stdio.h>

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &(a[i]));
	}
	int mx = 0, mxi;
	for (i = 1; i < (1 << n); i++)
	{
		int s[n], sc = 0;
		for (j = 0; j < n; j++)
		{
			if (((1 << j)&i) != 0)
			{
				s[sc++] = j;
			}
		}
		for (j = 1; j < sc; j++)
		{
			if (a[s[j]] < a[s[j - 1]])
			{
				break;
			}
		}
		if (j == sc && sc > mx)
		{
			mx = sc;
			mxi = i;
		}
	}
	printf("%d\n", mx);
	for (i = 0; i < n; i++)
	{
		if (((1 << i)&mxi) != 0)
		{
			printf("%d ", a[i]);
		}
	}
	printf("\n");
}
