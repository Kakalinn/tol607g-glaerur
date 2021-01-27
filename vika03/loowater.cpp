#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m, i, j, x, r;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < m; i++) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	r = j = 0;
	for (i = 0; i < m; i++)
	{
		while (j < n && a[j] < b[i]) j++;
		if (j < n) r++, j++;
	}
	cout << r << endl;
	return 0;
}
