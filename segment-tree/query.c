int queryl(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryl(p, i, m, x, LEFT(e)) + p[RIGHT(e)])
                    : (queryl(p, m + 1, j, x, RIGHT(e)));
}

int queryr(int* p, int i, int j, int x, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	return (x <= m) ? (queryr(p, i, m, x, LEFT(e)))
                    : (p[LEFT(e)] + queryr(p, m + 1, j, x, RIGHT(e)));
}

int query(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) return p[e];
	int m = (i + j)/2;
	if (x <= m && y <= m) return query(p, i, m, x, y, LEFT(e));
	if (x > m && y > m) return query(p, m + 1, j, x, y, RIGHT(e));
	return queryl(p, i, m, x, LEFT(e)) + queryr(p, m + 1, j, y, RIGHT(e));
}
