// https://cp-algorithms.com/string/aho_corasick.html
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0
listnode->n : index of the next node.
listnode->v : value of the current node.

trienode->l : index of the pattern that ends here, -1 if no pattern ends here.
trienode->e : indext of the nodes exit link.
				The exit link is the first leaf that is reached by following suffix links.
				If there is no leaf reachable by suffix links the exit link is the root (which is never a leaf).
				Note that the exit link of a leaf is the node itself.
trienode->p : index of parent.
trienode->c : character of the incoming edge.
trienode->d : memoization table for suffix links.
trienode->t : transition table of the trie.

trie->s : total number of used nodes.
trie->r : the index of the root of the trie.
#endif

#define ALPHABET 128
#define MAXN 1000000
typedef struct { int v, n; } listnode;
typedef struct { int t[ALPHABET], l, e, p, c, d; } trienode;
typedef struct { int s, r, l; trienode m[MAXN]; listnode w[MAXN];} trie;
int val(char c) { return c; }
int list_node(trie *t, int v, int n)
{
	t->w[t->l].v = v, t->w[t->l].n = n;
	return t->l++;
}
int trie_node(trie *t, int p, int c)
{
	int i;
	for (i = 0; i < ALPHABET; i++)
		t->m[t->s].t[i] = -1;
	t->m[t->s].l = -1, t->m[t->s].e = -1, t->m[t->s].p = p,
		t->m[t->s].c = c, t->m[t->s].d = -1;
	return t->s++;
}
void trie_init(trie *t) { t->s = t->l = 0, t->r = trie_node(t, -1, -1); }

void trie_insert(trie *t, char *s, int x)
{
	int h;
	for (h = t->r; *s; h = t->m[h].t[val(*s++)])
		if (t->m[h].t[val(*s)] == -1)
			t->m[h].t[val(*s)] = trie_node(t, h, val(*s));
	t->m[h].l = list_node(t, x, t->m[h].l);
}

int trie_step(trie*, int, int);
int trie_suffix(trie *t, int h)
{ // dp-lookup hjálparfall fyrir suffix link
	if (t->m[h].d != -1) return t->m[h].d;
	if (h == t->r || t->m[h].p == t->r) return t->m[h].d = t->r;
	return t->m[h].d = trie_step(t, trie_suffix(t, t->m[h].p), t->m[h].c);
}

int trie_step(trie *t, int h, int c)
{ // dp-lookup hjálparfall til að ítra
	if (t->m[h].t[c] != -1) return t->m[h].t[c];
	return t->m[h].t[c] = h == t->r ? t->r :
		trie_step(t, trie_suffix(t, h), c);
}

int trie_exit(trie *t, int h)
{ // dp-lookup hjálparfall fyrir exit link
	if (t->m[h].e != -1) return t->m[h].e;
	if (h == 0 || t->m[h].l != -1) return t->m[h].e = h;
	return t->m[h].e = trie_exit(t, trie_suffix(t, h));
}

trie t; // global svo það keyri locally.
int aho_corasick(char *s, char **p, int m)
{
	trie_init(&t);
	int h, i, j, k, w, l[m];
	for (i = 0; i < m; i++) l[i] = strlen(p[i]);
	for (i = 0; i < m; i++) trie_insert(&t, p[i], i);
	printf("             ");
	for (i = 0; i < strlen(s); i++) printf("%d", i%10); printf("\n");
	printf("searching in %s\n", s);
	for (i = 0, j = 0, h = t.r; ; j++)
	{
		k = trie_exit(&t, h);
		while (t.m[k].l != -1)
		{
			for (w = t.m[k].l; w != -1; w = t.w[w].n)
			{
				printf("  '%s' found at index %d\n",
						p[t.w[w].v], j - l[t.w[w].v]);
			}
			k = trie_exit(&t, trie_suffix(&t, k));
		}
		h = trie_step(&t, h, val(*s));
		if (*s++ == '\0') break;
	}
	return i;
}

int main()
{
	int i, j, n;
	char s[200001], p[200001], *a[100000];
	fgets(s, sizeof s, stdin);
	n = atoi(s);
	char *pp = p;
	for (i = 0; i < n; i++)
	{
		fgets(pp, sizeof p, stdin);
		pp[strcspn(pp, "\n")] = 0;
		a[i] = pp;
		pp += strlen(pp) + 1;
	}
	fgets(s, sizeof s, stdin);
	s[strcspn(s, "\n")] = 0;
	int m = aho_corasick(s, a, n);
	return 0;
}
