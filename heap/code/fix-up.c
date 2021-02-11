void fix_up(int i)
{
	if (i == 0) return;
	else if (h[i] > h[PARENT(i)])
	{
		swap(h[i], h[PARENT(i)]);
		fix_up(PARENT(i));
	}
}
