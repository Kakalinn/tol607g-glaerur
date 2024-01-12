// https://cp-algorithms.com/string/aho_corasick.html
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHABET 128
#define MAXN 1000000
typedef struct { int v, n; } listnode;
typedef struct { int t[ALPHABET], l, e, p, c, d; } trienode;
typedef struct { int s, r, l; trienode m[MAXN + 1]; listnode w[MAXN];} trie;
int val(char c) { return c; }                                                   // Varpar stöfunum á tölurnar 1, 2, ..., |Sigma|.
int list_node(trie *t, int v, int n)                                            // Einfaldur listi til að halda utan hvaða strengir enda í tilteknum hnút.
{
    t->w[t->l].v = v, t->w[t->l].n = n;
    return t->l++;
}
int trie_node(trie *t, int p, int c)                                            // Úthlutar tómum hnút með gildi c og foreldri p.
{
    for (int i = 0; i < ALPHABET; i++) t->m[t->s].t[i] = -1;                    // Upphafstillum hnútinn með engin börn.
    t->m[t->s].l = t->m[t->s].e = t->m[t->s].d = -1;                            // Upphafstillum minnistöflu gildin.
        t->m[t->s].p = p, t->m[t->s].c = c,                                     // Upphafstillum foreldri og gildi.
    return t->s++;                                                              // Skilum hnútnum.
}
void trie_init(trie *t) { t->s = t->l = 0, t->r = trie_node(t, -1, -1); }       // Upphafstillum tómt forstrengstré.

void trie_insert(trie *t, char *s, int x)                                       // Setur s inn í forstrengstréð t. Strengurinn er x-ti strengurinn.
{
    int h;
    for (h = t->r; *s; h = t->m[h].t[val(*s++)])                                // Ferðumst eftir forstrengstrénu.
        if (t->m[h].t[val(*s)] == -1)
            t->m[h].t[val(*s)] = trie_node(t, h, val(*s));                      // Ef hnúturinn er ekki til búum við hann til.
    t->m[h].l = list_node(t, x, t->m[h].l);                                     // Bætum x í listann.
}

int trie_step(trie*, int, int);                                                 // trie_step(...) og trie_suffix(...) eru háð hvoru öðru.
int trie_suffix(trie *t, int h)                                                 // Endurkvæmt fall með minnun sem reiknar bakstrengsleggina.
{
    if (t->m[h].d != -1) return t->m[h].d;
    if (h == t->r || t->m[h].p == t->r) return t->m[h].d = t->r;
    return t->m[h].d = trie_step(t, trie_suffix(t, t->m[h].p), t->m[h].c);
}

int trie_step(trie *t, int h, int c)                                            // Endurkvæmt fall með minnun sem reiknar færslu eftir staf c.
{
    if (t->m[h].t[c] != -1) return t->m[h].t[c];
    return t->m[h].t[c] = h == t->r ? t->r :
        trie_step(t, trie_suffix(t, h), c);
}

int trie_exit(trie *t, int h)                                                   // Endurkvæmt fall með minnun sem reiknar lokaleggina.
{
    if (t->m[h].e != -1) return t->m[h].e;
    if (h == 0 || t->m[h].l != -1) return t->m[h].e = h;
    return t->m[h].e = trie_exit(t, trie_suffix(t, h));
}

trie t;
int aho_corasick(char *s, char **p, int m)                                      // Finnur hvar strengirnir í p koma fyrir í s.
{
    trie_init(&t);
    int h, i, j, k, w, l[m];
    for (i = 0; i < m; i++) l[i] = strlen(p[i]);                                // Reiknum lengdirnar á strengjunum í p til að geta hliðrað svörunum rétt.
    for (i = 0; i < m; i++) trie_insert(&t, p[i], i);                           // Setjum i-ta strenginn í forstrengstréð.
    printf("             ");
    for (i = 0; i < strlen(s); i++) printf("%d", i%10); printf("\n");
    printf("searching in %s\n", s);
    for (i = 0, j = 0, h = t.r; ; j++)                                          // Ítrum í gegnum s og ferðumst eftir stöðuvélinni.
    {
        k = trie_exit(&t, h);                                                   // Ferðumst eftir lokalegg.
        while (t.m[k].l != -1)
        {
            for (w = t.m[k].l; w != -1; w = t.w[w].n)                           // Ítrum í gegnum alla strengina sem enda í hnútnum sem við erum í.
                printf("  '%s' found at %d\n", p[t.w[w].v], j - l[t.w[w].v]);
            k = trie_exit(&t, trie_suffix(&t, k));                              // Ferðumst eftir lokalegg.
        }
        h = trie_step(&t, h, val(*s));                                          // Hliðrum okkur í stöðuvélinni.
        if (*s++ == '\0') break;                                                // Hliðrum s og hættum ef s er tómur.
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
