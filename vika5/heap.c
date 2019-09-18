#include <stdio.h>
#define PARENT(i) ((i - 1)/2)
#define LEFT(i)   ((i)*2 + 1)
#define RIGHT(i)  ((i)*2 + 2)

int h[1000000];
int hn = 0;

void fix_down(int i)
{
	int mx = i;
	if (RIGHT(i) < hn && h[mx] < h[RIGHT(i)])
	{
		mx = RIGHT(i);
	}
	if (LEFT(i) < hn && h[mx] < h[LEFT(i)])
	{
		mx = LEFT(i);
	}
	if (mx != i)
	{
		int s = h[i];
		h[i] = h[mx];
		h[mx] = s;
		fix_down(mx);
	}
}

void fix_up(int i)
{
	if (i == 0)
	{
		return;
	}
	else if (h[i] > h[PARENT(i)])
	{
		int s = h[i];
		h[i] = h[PARENT(i)];
		h[PARENT(i)] = s;
		fix_up(PARENT(i));
	}
}

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

int main()
{
	int i;
	while (1)
	{
		scanf("%d", &i);
		if (i == 0)
		{
			pop();
			printf("> > ");
			for (i = 0; i < hn; i++)
			{
				printf("%d ", h[i]);
			}
			printf("\n");
		}
		else
		{
			push(i);
			printf("> > ");
			for (i = 0; i < hn; i++)
			{
				printf("%d ", h[i]);
			}
			printf("\n");
		}
	}
}
