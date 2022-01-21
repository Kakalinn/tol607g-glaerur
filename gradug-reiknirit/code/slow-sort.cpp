#include <bits/stdc++.h>
using namespace std;

void sort(int *a, int n)
{
	int i, j, mn;
	for (i = 0; i < n; i++)
	{
		mn = i;
		for (j = i; j < n; j++) if (a[mn] > a[j]) mn = j;
		swap(a[i], a[mn]);
	}
}

int main()
{
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a, n);
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
