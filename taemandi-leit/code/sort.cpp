#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, n, i;
	cin >> n;
	vector<int> p, a, b(n);
	for (i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
		p.push_back(i);
	}
	do {

		for (i = 0; i < n; i++) b[i] = a[p[i]];
		for (i = 0; i < n - 1; i++) if (b[i] > b[i + 1]) break;
		if (i == n - 1) break;
	} while (next_permutation(p.begin(), p.end()));
	for (i = 0; i < n; i++) cout << a[p[i]] << ' ';
	cout << endl;
	return 0;
}
