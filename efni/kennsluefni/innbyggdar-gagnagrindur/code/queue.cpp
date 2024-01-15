#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, n = 10;
	queue<int> a;
	for (i = 0; i < 10; i++) a.push(i);                                         // Setur i inn í biðröðina fyrir i = 1, 2, ..., 10.
	while (a.size() > 0)
	{
		printf("%d ", a.front());                                               // Á meðan biðröðin er ekki tóm prentum við fremsta stakið og fjarlægjum það.
		a.pop();
	}
	printf("\n");
	return 0;
}
