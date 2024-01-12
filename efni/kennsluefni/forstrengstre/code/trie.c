// https://cp-algorithms.com/string/aho_corasick.html
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET 26
#define MAXN 1000000
typedef struct { int t[ALPHABET], v; } trienode;
typedef struct { int s, r; trienode m[MAXN + 1]; } trie;
int trie_val(char c) { return c - 'a'; }                                        // Varpar stöfunum á tölurnar 1, 2, ..., |Sigma|.
int trie_node(trie *t, int v)                                                   // Úthlutar tómum hnút með gildi v.
{
    for (int i = 0; i < ALPHABET; i++) t->m[t->s].t[i] = -1;                    // Upphafstillum hnútinn með engan börn.
    t->m[t->s].v = v;                                                           // Upphafstillum hnútinn með réttu gildi.
    return t->s++;                                                              // Úthlutum hnútnum.
}
void trie_init(trie *t) { t->s = 0, t->r = trie_node(t, 0); }                   // Upphafstillir tómt forstrengstré.

void trie_insert(trie *t, char *s)                                              // Setur strenginn s inn í forstrengstréð t.
{
    int h;
    for (h = t->r; *s; h = t->m[h].t[trie_val(*s++)])                           // Ítrum í gegnum tréð.
        if (t->m[h].t[trie_val(*s)] == -1)                                      // Ef nágranninn er ekki til þarf að búa hann til.
            t->m[h].t[trie_val(*s)] = trie_node(t, 0);
    t->m[h].v = 1;                                                              // Merkjum hnútinn sem við endum í sem lokahnút.
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
