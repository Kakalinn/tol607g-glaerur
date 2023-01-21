#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, i;
	cin >> n;                                                                   // Innlestur.
	vector<int> p;
	for (i = 0; i < n; i++) p.push_back(i + 1);                                 // Upphafstillir fyrstu umröðunina.
	do {
		for (i = 0; i < n; i++) cout << p[i] << ' ';                            // Prentar tiltekna umröðun.
		cout << '\n';
	} while (next_permutation(p.begin(), p.end()));                             // Fer í næstu umröðun.
	return 0;
}
