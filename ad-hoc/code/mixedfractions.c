#include <stdio.h>

int main()
{
	int p, q, a, b, c;
	scanf("%d%d", &p, &q);
	a = p/q;
	b = p%q;
	c = q;
	printf("%d %d / %d\n", a, b, c);
	return 0;
}

/* */

#include <stdio.h>

int main()
{
	int p, q;
	scanf("%d%d", &p, &q);
	printf("%d %d / %d\n", p/q, p%q, q);
	return 0;
}
