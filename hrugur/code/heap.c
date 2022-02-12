#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b) { return a < b ? b : a; }
#define MAXN 1000000

#define PARENT(i) ((i - 1)/2)
#define LEFT(i)   ((i)*2 + 1)
#define RIGHT(i)  ((i)*2 + 2)
int h[MAXN], hn = 0;
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
void fix_down(int i) // Hjálparfall.
{ // Ferðast niður tréð og lagar hrúguskilyrðið á leiðinni.
	int mx = i;
	if (RIGHT(i) < hn && h[mx] < h[RIGHT(i)]) mx = RIGHT(i);
	if (LEFT(i) < hn && h[mx] < h[LEFT(i)]) mx = LEFT(i);
	if (mx != i) swap(&h[i], &h[mx]), fix_down(mx);
}

void fix_up(int i) // Hjálparfall.
{ // Ferðast upp tréð og lagar hrúguskilyrðið á leiðinni.
	if (i == 0 || h[i] <= h[PARENT(i)]) return;
	swap(&h[i], &h[PARENT(i)]), fix_up(PARENT(i));
}

void pop()
{ // Fjarlægir stærsta stakið.
	h[0] = h[--hn];
	fix_down(0);
}

int peek() { return h[0]; } // Skilar stærsta stakinu.
int size() { return hn; } // Skilar stærð hrúgurnar.
void push(int x)
{ // Bætir x við hrúguna.
	h[hn++] = x;
	fix_up(hn - 1);
}

int main()
{
	srand(time(NULL));
	int n = 100000, q = 10000, i, j, mx;
	int a[n], b[n], c[n];
	for (i = 0; i < n; i++) a[i] = rand();
	for (b[0] = a[0], i = 1; i < n; i++) b[i] = max(b[i - 1], a[i]);
	for (c[n - 1] = a[n - 1], i = n - 2; i >= 0; i--) c[i] = max(c[i + 1], a[i]);
	for (i = 0; i < n; i++)
	{
		push(a[i]);
		assert(b[i] == peek());
	}
	while (q--)
	{
		j = rand()%size();
		mx = 0;
		for (i = 0; i < n; i++) if (a[mx] < a[i]) mx = i;
		assert(a[mx] == peek());
		pop(), a[mx] = -1;
	}
	return 0;
}
