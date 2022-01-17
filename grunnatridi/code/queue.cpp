#include <bits/stdc++.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int i, n = 10;
	queue<int> a;
	for (i = 0; i < 10; i++) a.push(i);
	while (a.size() > 0)
	{
		printf("%d ", a.front());
		a.pop();
	}
	printf("\n");
	return 0;
}
