#include <stdio.h>
#include <stdlib.h>
typedef int ll;
#define MAXN 1000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
ll st_qrec(ll *p, ll i, ll j, ll x, ll y, ll e)                                 // Við erum að leita að bili [x, y] og erum í [i, j].
{
    if (x == i && y == j) return p[e];                                          // Við fundum akkúrat bilið.
    ll m = (i + j)/2;                                                           // Finnum miðju bilsins sem við erum að leita í.
    if (y <= m) return st_qrec(p, i, m, x, y, LEFT(e));                         // Bilið sem við erum að leita að er vinstra megin við miðjuna.
    if (x > m) return st_qrec(p, m + 1, j, x, y, RIGHT(e));                     // Bilið sem við erum að leita að er hægra megin við miðjuna.
    return st_qrec(p, i, m, x, m, LEFT(e)) +
        st_qrec(p, m + 1, j, m + 1, y, RIGHT(e));                               // Miðjan skiptir bilinu í tvennt.
}
ll st_query(ll *p, ll x, ll y) { return st_qrec(p, 0, p[0] - 1, x, y, 1); }     // Finnum summuna yfir [x, y].

void st_urec(ll *p, ll i, ll j, ll x, ll y, ll e)                               // Við erum að leita að laufinu [x, x] og erum í [i, j].
{
    if (i == j) p[e] = y;                                                       // Við erum komin í lauf.
    else
    {
        ll m = (i + j)/2;                                                       // Finnum miðjuna á bilinu sem við erum í.
        if (x <= m) st_urec(p, i, m, x, y, LEFT(e));                            // Laufið sem við erum að leita að er vinstra megin við miðjuna.
        else st_urec(p, m + 1, j, x, y, RIGHT(e));                              // Laufið sem við erum að leita að er hægra megin við miðjuna.
        p[e] = p[LEFT(e)] + p[RIGHT(e)];                                        // Lögum summun sem er geymd í hnútnum sem við erum í.
    }
}
void st_update(ll *p, ll x, ll y) { return st_urec(p, 0, p[0] - 1, x, y, 1); }  // Bætum y við x-ta stakið.
void st_init(ll *p, ll n) {for (ll i = 0; i < 5*n; i++) p[i] = i == 0 ? n : 0;} // Upphafstillum tréð. Fylkið p þarf að rúma 5*n stök!


typedef struct {ll x, y;} ii;
int cmpx(const void* p1, const void* p2)
{
    if (((ii*)p1)->x == ((ii*)p2)->x) return ((ii*)p1)->y - ((ii*)p2)->y;
    return ((ii*)p1)->x - ((ii*)p2)->x;
}

void compress(ll* a, ll n)
{
    ii b[n];
    for (ll i = 0; i < n; i++) b[i].x = a[i], b[i].y = i;                       // Búum til lista af tvenndum (a_i, i).
    qsort(b, n, sizeof(b[0]), cmpx);                                            // Röðum listanum eftir fyrra stakinu.
    for (ll i = 0; i < n; i++) a[b[i].y] = i;                                   // Látum i-tu minnstu töluna vera i.
}

long long teljum_umhverfingar(ll* a, ll n)                                      // a er umröðun, þ.e.a.s. inniheldur nákvæmlega 0, 1, ..., n - 1.
{                                                                               //   Fallið telur fjölda umhverfinga.
    ll p[5*n], b[n], i; long long r = 0;
    compress(a, n);
    st_init(p, n);                                                              // Núllstillum biltréð.
    for (i = 0; i < n; i++) st_update(p, i, 1);                                 // Upphafstillum biltréð með 1 allstaðar.
    for (i = 0; i < n; i++) b[a[i]] = i;                                        // Reiknum staðsetningarnar á öllum tölunum.
    for (i = 0; i < n; i++)
        r += b[i] != 0 ? st_query(p, 0, b[i] - 1) : 0, st_update(p, b[i], 0);   // Teljum fjölda skiptinga sem þarf til að setja i í i-ta sætið.
    return r;                                                                   // Skilum heildartalningunni.
}

#if 0
7
4 1 6 5 7 3 2
#endif
int main()
{
    ll n, i;
    scanf("%d", &n);                                                            // Innlestur hafinn.
    ll a[n];
    for (i = 0; i < n; i++) scanf("%lld", &a[i]);                               // Innlestri lokið.
    printf("%lld\n", teljum_umhverfingar(a, n));                                // Reiknum og prentum svarið.
}

