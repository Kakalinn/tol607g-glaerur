#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
int max(int a, int b) { return a < b ? b : a; }
#define MAXN 100000

#define PARENT(i) ((i)/2)                                                       // Reiknar foreldri i.
#define LEFT(i)   ((i)*2)                                                       // Reiknar vinstra barn i.
#define RIGHT(i)  ((i)*2 + 1)                                                   // Reiknar hægra barn i.
int h[MAXN + 1];
void swap(int* x, int* y) { int t = *x; *x = *y; *y = t; }
void fix_down(int i)                                                            // Fall sem lagar hrúguskilyrðið í i og ferðast niður.
{
	int mx = i;
	if (RIGHT(i) <= h[0] && h[mx] < h[RIGHT(i)]) mx = RIGHT(i);                 // Er hægra barnið stærra en rótin?
	if (LEFT(i) <= h[0] && h[mx] < h[LEFT(i)]) mx = LEFT(i);                    // Er vinstra barnið stærra en rótin?
	if (mx != i) swap(&h[i], &h[mx]), fix_down(mx);                             // Lögum ef það þarf og ferðumst niður tréð.
}

void fix_up(int i)                                                              // Fall sem ferðast upp tréð og lagar hrúguskilyrðið á leiðinni.
{
	if (i == 1 || h[i] <= h[PARENT(i)]) return;                                 // Skoðum hvort við séum kominn efst í tréð eða það þurfi ekki að laga.
	swap(&h[i], &h[PARENT(i)]), fix_up(PARENT(i));                              // Lögum og ferðumst upp tréð.
}

void pop()                                                                      // Fall sem fjarlægir stærsta stakið.
{
	h[1] = h[h[0]--];                                                           // Setjum 'aftasta' stakið í trénu í rótina.
	fix_down(1);                                                                // Lögum tréð.
}

void push(int x)                                                                // Fall sem bætir x í hrúguna.
{
	h[++h[0]] = x;                                                              // Setjum x 'aftast' í hrúguna.
	fix_up(h[0]);                                                               // Lögum tréð.
}

int peek() { return h[1]; }                                                     // Fall sem skilar stærsta stakinu.
int size() { return h[0]; }                                                     // Fall sem skilar stærð hrúgurnar.
void init() { h[0] = 0; }                                                       // Fall sem upphafstillir tóma hrúgu.


int main()
{
	srand(time(NULL));
	int n = 100000, q = 100000, i, j, mx;
	int a[n], b[n], c[n];
	init();
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
