#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, i, j, x, r;
	vector<int> a, b;
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	for (i = 0; i < m; i++)
	{
		cin >> x;
		b.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	r = j = 0;
	for (i = 0; i < n; i++)
	{
		while (j < m && b[j] < a[i]) j++;
		if (j < m) r++, j++;
	}
	printf("%d\n", r);
}
