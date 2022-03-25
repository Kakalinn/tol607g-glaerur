#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct snode node;
struct snode { node *n; int v; };
typedef struct { node *h, *t; } list;
list *list_init() { list* r = malloc(sizeof r); r->h = r->t = NULL; return r; }
node *init_node(node *n, int v) { node *r = malloc(sizeof r); r->n = n; r->v = v; return r; }
void list_free(list *l)
{
	node *x = l->h, *y;
	while (x) y = x, x = x->n, free(y);
	free(l);
}

int list_find(list *l, int t)
{ // is |t| in |l|?
	node *x = l->h;
	while (x && x->v == t) x = x->n;
	return x != NULL;
}

int list_rem(list *l, int t)
{
	node *x, *p, **y;
	if (l->h == NULL) return 0;
	if (l->h->v == t)
	{
		x = l->h;
		l->h = l->h->n;
		if (!l->h) l->t = NULL;
		free(x);
		return 1;
	}
	x = l->h;
	while (x && x->v != t) y = &x->n, p = x, x = x->n;
	if (!x) return 0;
	*y = x->n;
	if (!x->n) l->t = p;
	free(x);
	return 1;
}

void list_add(list *l, int t)
{
	node *x = l->h, **y = &l->h;
	while (x && x->v < t) y = &x->n, x = x->n;
	*y = init_node(x, t);
	if (!x) l->t = *y;
}

void list_print(list *l)
{
	node *x = l->h;
	printf("list: ");
	while (x) printf("%3d ", x->v), x = x->n;
	printf("\n");
}

int arr_add(int *a, int n, int x)
{
	int i;
	for (i = n; i > 0 && a[i - 1] > x; i--) a[i] = a[i - 1];
	a[i] = x;
}

int arr_rem(int *a, int n, int x)
{
	int i;
	for (i = 0; i < n && a[i] != x; i++);
	if (i == n) return 0;
	for (; i < n - 1; i++) a[i] = a[i + 1];
	return 1;
}

int arr_print(int *a, int n)
{
	int i;
	printf("arr:  ");
	for (i = 0; i < n; i++) printf("%3d ", a[i]);
	printf("\n");
}

int comp(list *l, int *a)
{
	int i = 0;
	node *x = l->h;
	while (x && a[i++] == x->v) x = x->n;
	return x == NULL;
}

int main()
{
	srand(time(NULL));
	list *l = list_init();
	int s = 0, n = 1000, q = -1;
	int a[n];
	while (q--)
	{
		if (s == n)
		{
			int k = rand()%n;
			list_rem(l, a[k]);
			arr_rem(a, s--, a[k]);
		}
		int k = rand();
		list_add(l, k);
		arr_add(a, s++, k);
		if (!comp(l, a))
		{
			break;
			list_print(l);
			arr_print(a, s);
			break;
		}
	}
	list_free(l);
	return 0;
}
