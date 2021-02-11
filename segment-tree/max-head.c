int queryl(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (max(queryl(p, i, m, x, LEFT(e)), p[RIGHT(e)]))
                    : (queryl(p, m + 1, j, x, RIGHT(e)));
}
int queryr(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryr(p, i, m, x, LEFT(e)))
                    : (max(p[LEFT(e)], queryr(p, m + 1, j, x, RIGHT(e))));
}
int query(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query(p, i, m, x, y, LEFT(e));
	if (x > m && y > m) return query(p, m + 1, j, x, y, RIGHT(e));
	return max(queryl(p, i, m, x, LEFT(e)), queryr(p, m + 1, j, y, RIGHT(e)));
}
void update(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) update(p, i, m, x, y, LEFT(e));
		else update(p, m + 1, j, x, y, RIGHT(e));
		p[e] = max(p[LEFT(e)], p[RIGHT(e)]);
	}
}
