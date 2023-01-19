#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));                                                          // Upphafstillum slembitalnaframleiðandann.
	int i, n = 10;
	set<int> a;
	while (a.size() < 10) a.insert(rand()%100);                                 // Setjum allt að tíu slebmnar tölur í a.
	while (a.size() > 0)
	{
		printf("%2d ", *a.begin());                                             // Á meðan a er ekki tómt prentum við fremsta stakið og fjarlægjum það.
		a.erase(a.begin());
	}
	printf("\n");
	return 0;
}
