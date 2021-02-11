// ath: p er af staerd 4*n + 1
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
void update(int* p, int i, int j, int x, int y, int e)
{
	if (i == j) p[e] = y;
	else
	{
		int m = (i + j)/2;
		if (x <= m) update(p, i, m, x, y, LEFT(e));
		else update(p, m + 1, j, x, y, RIGHT(e));
		p[e] = p[LEFT(e)] + p[RIGHT(e)];
	}
}
