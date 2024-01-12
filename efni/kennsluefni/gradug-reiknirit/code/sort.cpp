#include <bits/stdc++.h>
using namespace std;

void sort(int *a, int n)
{
    int i;
    priority_queue<int> q;
    for (i = 0; i < n; i++) q.push(-a[i]);                                      // Setjum allar tölurnar í forgangsbiðröð.
    for (i = 0; i < n; i++) a[i] = -q.top(), q.pop();                           // Tökum fremstu töluna í forgangsbiðröðinni og setju aftast í listann.
}

int main()
{
    int i, n;
    cin >> n;                                                                   // Innlestur hefst.
    int a[n];
    for (i = 0; i < n; i++) cin >> a[i];                                        // Innlestri lokið.
    sort(a, n);                                                                 // Röðum listanum.
    for (i = 0; i < n; i++) printf("%d ", a[i]);                                // Prentum listann.
    printf("\n");
    return 0;
}
