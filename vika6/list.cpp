#include <iostream>

using namespace std;

typedef struct snode
{
	int v;
	struct snode* n;
} node;

class llist
{
	public:
	node* h;
	node* t;
	llist()
	{
		h = NULL; t = NULL;
	}
	void add(int n)
	{
		node* a = new node;
		a->v = n;
		a->n = NULL;
		if (h == NULL)
		{
			h = a; t = a;
		}
		else
		{
			t->n = a;
			t = t->n;
		}
	}
	bool find(int n)
	{
		node* g = h;
		while (g != NULL)
		{
			if (g->v == n)
			{
				break;
			}
			g = g->n;
		}
		return g != NULL;
	}
	bool del(int n)
	{
		if (h->v == n)
		{
			if (h == t)
			{
				delete h;
				h = NULL; t = NULL;
				return true;
			}
			node* g = h;
			h = h->n;
			delete g;
			return true;
		}
		node* gg = h;
		node* g = h->n;
		while (g != NULL)
		{
			if (g->v == n)
			{
				break;
			}
			gg = g;
			g = g->n;
		}
		if (g == NULL)
		{
			return false;
		}
		gg->n = g->n;
		if (g == t)
		{
			t = gg;
		}
		delete g;
		return true;

	}
};

int main()
{
	llist a;
	a.add(3); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(5); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(1); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(4); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(2); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(2); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(3); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(1); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(5); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(4); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(3); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(5); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(1); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(4); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.add(2); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(2); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(3); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(1); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(5); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	a.del(4); cout << a.find(1) << a.find(2) << a.find(3) << a.find(4) << a.find(5) << endl;
	return 0;
}

