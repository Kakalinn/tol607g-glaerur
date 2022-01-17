#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int i;
	list<int> a;
	for (i = 1; i <= 5; i++) a.push_back(i);
	for (i = 1; i <= 5; i++) a.push_front(i);
	for (auto p : a) printf("%d ", p);
	printf("\n");
	return 0;
}
