int p[MAX];

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
	int i;
	int n = MAX;
	for (i = 0; i < n; i++) p[i] = i;
	...
}
