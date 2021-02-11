void pop()
{
	hn--;
	h[0] = h[hn];
	fix_down(0);
}

int peek()
{
	return h[0];
}

void push(int x)
{
	h[hn++] = x;
	fix_up(hn - 1);
}
