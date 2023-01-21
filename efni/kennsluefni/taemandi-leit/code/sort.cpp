#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, n, i;
	cin >> n;                                                                   // Innlestur hefst.
	vector<int> p, a, b(n);
	for (i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
		p.push_back(i);
	}                                                                           // Innlestri lokið.
	do {
		for (i = 0; i < n; i++) b[i] = a[p[i]];                                 // Finnum tilteknu umröðun listans.
		for (i = 0; i < n - 1; i++) if (b[i] > b[i + 1]) break;                 // Skoðum hvort tiltekin umröðun sé vaxandi.
		if (i == n - 1) break;                                                  // Ef tiltekin umröðun er vaxandi getum vid hætt að leita.
	} while (next_permutation(p.begin(), p.end()));
	for (i = 0; i < n; i++) cout << a[p[i]] << ' ';                             // Prentum svarið.
	cout << endl;
	return 0;
}
