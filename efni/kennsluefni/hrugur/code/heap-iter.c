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
void pop()                                                                      // Fjarlægir stærsta stakið.
{
	h[1] = h[h[0]--];                                                           // Setjum 'aftasta' stakið í trénu í rótina.
	for (int i = 1, mx = i; ; swap(&h[i], &h[mx]), i = mx)                      // Löbbum upp og lögum tréð.
	{
		if (RIGHT(i) <= h[0] && h[mx] < h[RIGHT(i)]) mx = RIGHT(i);             // Er hægra barnið stærra en rótin?
		if (LEFT(i) <= h[0] && h[mx] < h[LEFT(i)]) mx = LEFT(i);                // Er vinstra barnið stærra en rótin?
		if (i == mx) return;                                                    // Við erum búin að laga allt sem þarf að laga.
	}
}

void push(int x)                                                                // Bætir x í hrúguna.
{
	h[++h[0]] = x;                                                              // Setjum x 'aftast' í hrúguna.
	for (int i = h[0]; i > 1 && h[i] > h[PARENT(i)]; i = PARENT(i))             // Löbbum upp tréð á meðan það þarf að laga eitthvað.
		swap(&h[i], &h[PARENT(i)]);                                             // Lögum tréð.
}

int peek() { return h[1]; }                                                     // Skilar stærsta stakinu.
int size() { return h[0]; }                                                     // Skilar stærð hrúgurnar.
void init() { h[0] = 0; }                                                       // Upphafstillir tóma hrúgu.

int main()                                                                      // Prófar útfærsluna, en ekki nógu vel.
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
