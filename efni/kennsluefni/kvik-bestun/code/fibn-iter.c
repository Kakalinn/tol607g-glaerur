#include <stdio.h>

int main()
{
	int n, i;
	scanf("%d", &n);                                                            // Innlestur.
	int a[n];
	a[0] = a[1] = 1;                                                            // Grunntilfellin.
	for (i = 2; i < n; i++) a[i] = a[i - 1] + a[i - 2];                         // Fyllum up í minnistöfluna.
	printf("%d\n", a[n - 1]);                                                   // Prentum svarið.
	return 0;
}
