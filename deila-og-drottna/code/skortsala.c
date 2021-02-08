#include <stdlib.h>
#include <stdio.h>
typedef long long ll;
ll max(ll a, ll b) { if (a < b) return b; return a; }

ll foo(ll* a, ll l, ll r, ll k)
{
    if (r - l < 5)
    {
        ll i, j, mx = 0;
        for (i = l; i < r; i++) for (j = i + 1; j < r; j++)
            mx = max(mx, 100*(a[i] - a[j]) - k*(j - i));
        return mx;
    }
    ll m = (l + r)/2, i, j;
    ll v1 = foo(a, l, m, k), v2 = foo(a, m, r, k), mx1 = 0, mx2 = 0;
    for (i = l; i < m; i++) mx1 = max(mx1, 100*(a[i] - a[m]) - k*(m - i));
    for (i = m; i < r; i++) mx2 = max(mx2, 100*(a[m] - a[i]) - k*(i - m));
    return max(max(v1, v2), mx1 + mx2);
}

int main()
{
    ll i, j;
    int x, n, k;
    scanf("%d%d", &n, &k);
    ll a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        a[i] = x;
    }
    printf("%lld\n", max(0, foo(a, 0, n, k) - k));
    return 0;
}
