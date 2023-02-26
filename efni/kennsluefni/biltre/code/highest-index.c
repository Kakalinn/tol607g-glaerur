#include <stdio.h>
#include <assert.h>
#define MAXN 5000000
#define LEFT(x) ((x)*2)
#define RIGHT(x) ((x)*2 + 1)
int max(int a, int b) { return a < b ? b : a; }
int p[MAXN*5];

int find_m_mid(int i, int j, int g) { return (i + j)/2; }
int find_m_opt(int i, int j, int g)
{
	return (j - i + 1)&(g >> 1) ? i + g - 1 : j - g/2;
}

// [0, 13] : g = 8


/*
                      1
          2                       3
    4          5           6            7
 8     9     10    11    12    13    14    15
16 17 18 19 20 21 22 23 24 25 26 27   |     |
 |  |  |  |  |  |  |  |  |  |  |  |   12    13
 0  1  2  3  4  5  6  7  8  9  10 11
*/

/*
               +-----------------1-----------------+
       +-------2--------+                 +--------3--------+
   +---4---+        +---5---+         +---6---+         +---7---+
 +-8-+   +-9-+   +-10-+   +-11-+   +-12-+   +-13-+   +-14-+   +-15-+
16   17 18   19 20    21 22    23 24    25 26    27 28    29 30    31
*/

int qrec(int i, int j, int e, int g, int (*find_m)(int, int, int))
{
	if (i == j) return e;
	while (g > j - i + 1) g /= 2;
	int m = find_m(i, j, g);
	assert(i <= m && m <= j);
	return max(qrec(i, m, LEFT(e), g, find_m), qrec(m + 1, j, RIGHT(e), g, find_m));
}
int query(int n, int (*find_m)(int, int, int))
{
	return qrec(0, n - 1, 1, 1 << 30, find_m);
}

int qrec_seq(int i, int j, int e)
{
	if (i == j) return e;
	int m = (i + j)/2;
	return max(qrec_seq(i, m, e + 1), qrec_seq(m + 1, j, e + 2*(m - i + 1)));
}
int query_seq(int n)
{
	return qrec_seq(0, n - 1, 1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("n: mid opt 2*n - 1\n");
	printf("%d: %d %d %d %d\n", n, query(n, find_m_mid), query(n, find_m_opt), query_seq(n), 2*n - 1);
	return 0;
}
