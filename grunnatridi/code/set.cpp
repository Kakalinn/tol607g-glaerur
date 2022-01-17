#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int i, n = 10;
	set<int> a;
	while (a.size() < 10) a.insert(rand()%100);
	while (a.size() > 0)
	{
		printf("%2d ", *a.begin());
		a.erase(a.begin());
	}
	printf("\n");
	return 0;
}
