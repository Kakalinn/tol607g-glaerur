#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, i;
	cin >> n;
	vector<int> p;
	for (i = 0; i < n; i++) p.push_back(i + 1);
	do {
		for (i = 0; i < n; i++) cout << p[i] << ' ';
		cout << '\n';
	} while (next_permutation(p.begin(), p.end()));
	return 0;
}
