#include <bits/stdc++.h>
using namespace std;

void sort(int *a, int n)
{
	int i, j, mn;
	for (i = 0; i < n; i++)                                                     // Við munum þurfa að finna minnstu töluna n-sinnum.
	{
		for (j = mn = i; j < n; j++) if (a[mn] > a[j]) mn = j;                  // Finnum hvar minnsta talan er í listanum.
		swap(a[i], a[mn]);                                                      // Setjum minnstu töluna sem er eftir á sinn stað.
	}
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
