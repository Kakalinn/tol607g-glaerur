#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, n = 10;
	stack<int> a;
	for (i = 0; i < 10; i++) a.push(i);                                         // Setur i á hlaðann fyrir i = 1, 2, ..., 10.
	while (a.size() > 0)
	{
		printf("%d ", a.top());                                                 // Á meðan hlaðinn er ekki tómur prentum við efsta stakið og fjarlægjum það.
		a.pop();
	}
	printf("\n");
	return 0;
}
