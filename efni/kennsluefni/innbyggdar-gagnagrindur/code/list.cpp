#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i;
	list<int> a;
	for (i = 1; i <= 5; i++) a.push_back(i);                                    // Setur i aftast í listann fyrir i = 1, 2, 3, 4, 5.
	for (i = 1; i <= 5; i++) a.push_front(i);                                   // Setur i fremst í listann fyrir i = 1, 2, 3, 4, 5.
	for (auto p : a) printf("%d ", p);                                          // Ítrar í gegnum listan og prentar stökin.
	printf("\n");
	return 0;
}
