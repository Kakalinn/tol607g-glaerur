#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void merge(int* a, int l, int m, int r)
{
	int i = l, j = m, b[r - l], c = 0;
	while (i < m && j < r)
	{
		if (a[j] < a[i]) b[c++] = a[j++];
		else b[c++] = a[i++];
	}
	while (i < m) b[c++] = a[i++];
	while (j < r) b[c++] = a[j++];
	for (i = l; i < r; i++) a[i] = b[i - l];
}

void mergesort(int* a, int l, int r)
{
	if (r - l < 2) return;
	int m = (l + r)/2;
	mergesort(a, l, m), mergesort(a, m, r);
	merge(a, l, m, r);
}

int main()
{
	srand(time(NULL));
	int i, n;
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++) a[i] = rand()%(10*n);
	mergesort(a, 0, n);
	for (i = 0; i < n - 1; i++) assert(a[i] <= a[i + 1]);
	return 0;
}
