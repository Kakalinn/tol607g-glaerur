// https://cp-algorithms.com/string/aho_corasick.html
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET 26
#define MAXN 1000000
typedef struct { int t[ALPHABET], v; } trienode;
typedef struct { int s, r; trienode m[MAXN]; listnode w[MAXN];} trie;
int val(char c) { return c - 'a'; }
int trie_node(trie *t, int v)
{
	int i;
	for (i = 0; i < ALPHABET; i++) t->m[t->s].t[i] = -1;
	t->m[t->s].v = -1;
	return t->s++;
}
void trie_init(trie *t) { t->s = 0, t->r = trie_node(t, -1, -1); }

void trie_insert(trie *t, char *s, int x)
{
	int h;
	for (h = t->r; *s; h = t->m[h].t[val(*s++)])
		if (t->m[h].t[val(*s)] == -1)
			t->m[h].t[val(*s)] = trie_node(t, h, val(*s));
	t->m[h].v = 1;
}

int main()
{
#if 0
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
#endif
	return 0;
}
