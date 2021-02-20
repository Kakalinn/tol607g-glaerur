#define MAXN 1000000
int p[MAXN]; // = [-1, -1, ..., -1]
int find(int x)
{
	return p[x] < 0 ? x : (p[x] = find(p[x]));
}
void join(int x, int y)
{
	int rx = find(x), ry = find(y);
	if (rx == ry) return;
	if (p[rx] > p[ry]) p[ry] += p[rx], p[rx] = ry;
	else p[rx] += p[ry], p[ry] = rx;
}

int main()
{
	int i, n = MAXN;
	for (i = 0; i < n; i++) p[i] = -1;
	...
}
