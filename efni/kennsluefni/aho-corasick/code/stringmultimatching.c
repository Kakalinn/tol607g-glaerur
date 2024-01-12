// https://cp-algorithms.com/string/aho_corasick.html
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef long long ll;
int min(int a, int b) { if (a > b) return b; return a; }
int max(int a, int b) { if (a < b) return b; return a; }

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

// start
#define ALPHABET 96
#define MAXN 200000
typedef struct { int v, n; } listnode;
typedef struct { int t[ALPHABET], l, e, p, c, d; } trienode;
typedef struct { int s, r, l; trienode m[MAXN]; listnode w[MAXN];} trie;
int val(char c) { return c - ' '; }
int list_node(trie *t, int v, int n)
{
    t->w[t->l].v = v, t->w[t->l].n = n;
    return t->l++;
}
int trie_node(trie *t, int p, int c)
{
    for (int i = 0; i < ALPHABET; i++) t->m[t->s].t[i] = -1;
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
{
    if (t->m[h].d != -1) return t->m[h].d;
    assert(0);
    if (h == t->r || t->m[h].p == t->r) return t->m[h].d = t->r;
    return t->m[h].d = trie_step(t, trie_suffix(t, t->m[h].p), t->m[h].c);
}

int trie_step(trie *t, int h, int c)
{
    if (t->m[h].t[c] != -1) return t->m[h].t[c];
    assert(0);
    return t->m[h].t[c] = h == t->r ? t->r : trie_step(t, trie_suffix(t, h), c);
}

int trie_exit(trie *t, int h)
{
    if (t->m[h].e != -1) return t->m[h].e;
    assert(0);
    if (h == 0 || t->m[h].l != -1) return t->m[h].e = h;
    return t->m[h].e = trie_exit(t, trie_suffix(t, h));
}

void trie_dp(trie *t)
{
    int h, i, q[t->s], qs = 0, qe = 0;
    q[qe++] = 0;
    //printf(">>>>>> init dp %d\n", h);
    while (qe != qs)
    {
        h = q[qs++];
        for (i = 0; i < ALPHABET; i++) if (t->m[h].t[i] != -1)
            //printf(">>>>>> %d->%d\n", h, i),
            q[qe++] = t->m[h].t[i];
        //printf("t: "); for (i = 0; i < ALPHABET; i++) printf("%d ", t->m[h].t[i]); printf("\n");
        //printf("g: "); for (i = 0; i < gg; i++) printf("%d ", g[i]); printf("\n");
        if (h == t->r || t->m[h].p == t->r) t->m[h].d = t->r; // reiknar bakstrengsleggi, t->m[h].d
        else t->m[h].d = t->m[t->m[t, t->m[h].p].d].t[t->m[h].c];
        //trie_suffix(t, h);

        for (i = 0; i < ALPHABET; i++) if (t->m[h].t[i] == -1)
            t->m[h].t[i] = h == t->r ? t->r : t->m[t->m[h].d].t[i];

        //trie_exit(t, h); // reiknar t->m[h].e
        if (h == 0 || t->m[h].l != -1) t->m[h].e = h;
        else t->m[h].e = t->m[t->m[h].d].e;

        //printf("g: "); for (i = 0; i < gg; i++) printf("%d ", g[i]); printf("\n");
    }
}

ll topar(ll x, ll y) { return (x << 32) + y; }
ll first(ll x) { return x >> 32; }
ll second(ll x) { return x&((1LL << 32) - 1); }

trie t; // global svo það keyri locally.
int aho_corasick(char *s, char **p, int m, ll *r)
{
    trie_init(&t);
    int h, i, j, k, w, l[m];
    for (i = 0; i < m; i++) l[i] = strlen(p[i]);
    for (i = 0; i < m; i++) trie_insert(&t, p[i], i);
    trie_dp(&t);
    for (i = 0, j = 0, h = t.r; ; j++)
    {
        k = t.m[h].e; //trie_exit(&t, h);
        while (k != t.r)
        {
            for (w = t.m[k].l; w != -1; w = t.w[w].n)
                r[i++] = topar(t.w[w].v, j - l[t.w[w].v]);
            k = t.m[t.m[k].d].e; //k = trie_exit(&t, trie_suffix(&t, k));
        }
        h = t.m[h].t[val(*s)]; //h = trie_step(&t, h, val(*s));
        if (*s++ == '\0') break;
    }
    return i;
}

// end
char read_char()
{
    char r = fgetc_unlocked(stdin);
    if (r == EOF) exit(0);
    return r;
}

int get_string(char* b, char t)
{
    int i = 0;
    b[i++] = read_char();
    while (b[i - 1] != t) b[i++] = read_char();
    b[i - 1] = '\0';
    return i - 1;
}

int get_int()
{
    int r = 0, c = read_char(), s = 1;
    while (c != '-' && (c < '0' || c > '9')) c = read_char();
    while (c == '-') s *= -1, c = read_char();
    while ('0' <= c && c <= '9') r = r*10 + c - '0', c = read_char();
    return s*r;
}

#define CMP(E, F) (((F) <= (E)) - ((E) <= (F)))
int cmp(const void *p1, const void *p2) { return CMP(*(ll*)p1, *(ll*)p2); }

#define MAXM 480000
ll r[MAXM];
int main()
{
    int i, j, n = get_int();
    char s[200001], p[200001], *a[100000];
    while (n != EOF)
    {
        char *pp = p;
        for (i = 0; i < n; i++)
        {
            int m = get_string(pp, 10);
            a[i] = pp;
            pp += m + 1;
        }
        get_string(s, 10);
        int m = aho_corasick(s, a, n, r);
        qsort(r, m, sizeof *r, cmp);
        j = 0;
        for (i = 0; i < m; i++)
        {
            while (j != first(r[i])) j++, printf("\n");
            printf("%lld ", second(r[i]));
        }
        printf("\n");
        n = get_int();
    }
    return 0;
}
