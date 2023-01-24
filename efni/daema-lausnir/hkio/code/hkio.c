#include <stdio.h>

int main()
{
	int i, n, r;
	scanf("%d", &n);                                                            // Innlestur hefst.
	int a[n];
	for (i = 0; i < n; i++) scanf("%d", &a[i]);                                 // Innlestur hefst.
	for (r = i = 0; i < n; i++) if (a[i] > a[r]) r = i;                         // Finnum vísinn á stærstu töluna í listanum.
	printf("%d %d\n", r, r);                                                    // Prentum 'bilið' sem inniheldur stærstu töluna.
	return 0;
}
