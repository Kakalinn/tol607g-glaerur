#include <stdio.h>
#define MAXN 10000

int p[MAXN]; // = [0, 1, ..., n - 1]
int find(int x)
{
	if (p[x] == x) return x;
	return find(p[x]);
}

void join(int x, int y)
{
	p[find(x)] = find(y);
}

int main()
{
	int i, n = MAXN;
	for (i = 0; i < n; i++) p[i] = i;
	//...
	return 0;
}
