void fix_down(int i)
{
	int mx = i;
	if (RIGHT(i) < hn && h[mx] < h[RIGHT(i)]) mx = RIGHT(i);
	if (LEFT(i) < hn && h[mx] < h[LEFT(i)]) mx = LEFT(i);
	if (mx != i)
	{
		swap(h[i], h[mx]);
		fix_down(mx);
	}
}
