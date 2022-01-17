#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int i, n = 10;
	vector<int> a;
	for (i = 0; i < n; i++) a.push_back(rand()%100);
	for (i = 0; i < n; i++) printf("%2d ", a[i]);
	printf("\n");
	sort(a.begin(), a.end());
	for (i = 0; i < n; i++) printf("%2d ", a[i]);
	printf("\n");
	sort(a.rbegin(), a.rend());
	for (i = 0; i < n; i++) printf("%2d ", a[i]);
	printf("\n");
	return 0;
}
