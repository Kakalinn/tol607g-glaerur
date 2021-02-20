#define MAXN 1000000
int p[MAXN];

int find(int x)
{
	if (p[x] == x) return x;
	return p[x] = find(p[x]);
}

void join(int x, int y)
{
	p[find(x)] = find(y);
}

int main()
{
	int i, n = MAXN;
	for (i = 0; i < n; i++) p[i] = i;
	...
}
