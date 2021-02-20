#define PARENT(i) ((i - 1)/2)
#define LEFT(i)   ((i)*2 + 1)
#define RIGHT(i)  ((i)*2 + 2)
#define MAXN 1000000
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
	if (i == 0) return;
	else if (h[i] > h[PARENT(i)])
		swap(&h[i], &h[PARENT(i)]), fix_up(PARENT(i));
}

void pop()
{ // Fjarlægir stærsta stakið.
	h[0] = h[--hn];
	fix_down(0);
}

int peek() { return h[0]; } // Skilar stærsta stakinu.

void push(int x)
{ // Bætir x við hrúguna.
	h[hn++] = x;
	fix_up(hn - 1);
}
