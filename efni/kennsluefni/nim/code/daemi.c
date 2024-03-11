#include <stdio.h>
#include <assert.h>
#define MAXN 401

int mex(int* a, int n)                                                          // Skilar minnstu tölunni >= 0 sem er ekki í a.
{
    int b[n], i;
    for (i = 0; i < n; i++) b[i] = 0;
    for (i = 0; i < n; i++) if (a[i] < n) b[a[i]] = 1;
    for (i = 0; i < n; i++) if (!b[i]) break;
    return i;
}

int d[MAXN];
int dp_lookup(int x)                                                            // Notum kvika bestun til að reikna Grundy tölu stöðunnar x.
{
    if (x == 0) return 0;                                                       // Grunntilfelli.
    if (d[x] != -1) return d[x];                                                // Við erum búin að reikna svarið. Skilum því sem við reiknuðum þá.
    int i, j, a[x*x + 1];
    for (a[0] = 0, i = 0; i < x; i++) for (j = i; j < x; j++)                   // Ítrum í gegnum alla mögulega leiki.
        a[++a[0]] = dp_lookup(i)^dp_lookup(x - j - 1);                          // Reiknum Grundy tölu stöðunnar eftir leikinn.
    return d[x] = mex(a + 1, a[0]);                                             // Reiknum og skilum Grundy tölunni.
}

void finna_besta_leik(int *a, int n)
{
    int i, j, k, x, y;
    for (i = 0; i < n; i++) for (j = i; j < n; j++)                             // Ítrum í gegnum alla mögulega leiki.
    {
        for (k = i; k <= j; k++) if (!a[k]) break;
        if (k <= j) continue;                                                   // Ólöglegur leikur.
        for (k = i; k <= j; k++) a[k] = 0;                                      // Prófum að krota yfir alla reitina og athugum hvort það sé tapstaða.
        for (x = y = k = 0; k <= n; k++)                                        // Reiknum xor-summuna.
        {
            if (k == n || !a[k]) x ^= dp_lookup(y), y = 0;
            else y++;
        }
        if (!x) return;                                                         // Tapstaða var fundin.
        for (k = i; k <= j; k++) a[k] = 1;                                      // Afkrotum reitina því þetta var ekki tapstaða.
    }
    for (k = 0; k < n; k++) if (a[k]) break;                                    // Það er enginn vinningsleikur, þannig við leikum bara einhverju.
    a[k] = 0;
}

int main()
{
    int i, x, y, n, t, a[MAXN];
    printf("Hvað eru margir kassar í byrjun?\n");
    scanf("%d", &n);
    printf("Hver byrjar (0 fyrir þig, 1 fyrir tölvuna))?\n");
    scanf("%d", &t);
    for (i = 0; i < n + 1; i++) d[i] = -1;
    for (i = 0; i < n; i++) a[i] = i == n/2 ? 0 : 1;
    if (t) finna_besta_leik(a, n);
    while (1)
    {
        for (i = 0; i < n; i++) if (a[i]) break;
        if (i == n) { printf("Þú tapar!\n"); break; }
        for (i = 0; i < n; i++) printf("%2d ", i);
        printf("\n");
        for (i = 0; i < n; i++) printf(" %c ", a[i] ? '.' : 'X');
        printf("\n");
        scanf("%d%d", &x, &y);
        assert(x <= y && x >= 0 && y < n);
        for (i = x; i <= y; i++) assert(a[i]), a[i] = 0;
        for (i = 0; i < n; i++) if (a[i]) break;
        if (i == n) { printf("Þú vinnur!\n"); break; }
        finna_besta_leik(a, n);
    }
    return 0;
}

