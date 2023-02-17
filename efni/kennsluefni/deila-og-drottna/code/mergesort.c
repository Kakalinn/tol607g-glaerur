#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void merge(int* a, int l, int m, int r)
{
	int i = l, j = m, b[r - l], c = 0;
	while (i < m || j < r)
		b[c++] = (i == m || (j < r && a[j] < a[i])) ? a[j++] : a[i++];          // Látum í b stærri tölun sem er fremst í skiptingunum á a.
	for (i = l; i < r; i++) a[i] = b[i - l];                                    // Skrifum svo aftur inn í a, nú raðað.
}

void mergesort(int* a, int l, int r)
{
	if (r - l < 2) return;                                                      // Tómur listar og einstökungar eru raðaðir.
	int m = (l + r)/2;                                                          // Helmingum.
	mergesort(a, l, m), mergesort(a, m, r);                                     // Röðum hvorum helmingi.
	merge(a, l, m, r);                                                          // Sameinum helmingana.
}

int cmp(const void* p1, const void* p2)                                         // Samanburðarfall fyrir vaxandi röðun.
{
	int x = *(int*)p1, y = *(int*)p2;
	return (y <= x) - (x <= y);
}

int main()
{
	srand(time(NULL));
	int i, n;
	scanf("%d", &n);                                                            // Innlestur.
	int a[n], b[n];
	for (i = 0; i < n; i++) b[i] = a[i] = rand()%(10*n);                        // Veljum n slembnar tölur til að raða.
	mergesort(a, 0, n);                                                         // Röðum með mergesort.
	qsort(b, n, sizeof *b, cmp);                                                // Röðum með innbyggða qsort til samanburðar.
	for (i = 0; i < n; i++) assert(a[i] == b[i]);                               // Berum saman raðanirnar.
	return 0;
}
