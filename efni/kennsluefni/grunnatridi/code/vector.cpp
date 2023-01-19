#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));                                                          // Upphafstillum slembitalnaframleiðandann.
	int i, n = 10;
	vector<int> a;
	for (i = 0; i < n; i++) a.push_back(rand()%100);                            // Setjum tíu slembnar tölur í a.
	for (i = 0; i < n; i++) printf("%2d ", a[i]);                               // Prentum a.
	printf("\n");
	sort(a.begin(), a.end());                                                   // Röðum a í vaxandi röð.
	for (i = 0; i < n; i++) printf("%2d ", a[i]);                               // Prentum a.
	printf("\n");
	sort(a.rbegin(), a.rend());                                                 // Röðum a í minnkandi röð.
	for (i = 0; i < n; i++) printf("%2d ", a[i]);                               // Prentum a.
	printf("\n");
	return 0;
}
