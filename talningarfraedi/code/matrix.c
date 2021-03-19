#include <stdio.h>
#define rep(E, F) for (E = 0; E < (F); E++)
// Utfaersla a eindfoldum ferningsfylkjaadgerdum.

void addto(int* a, int* b, int n)
{ // Baetir fylkinu |b| vid fylkid |a|. Eins og `a += b`.
	int i, j;
	rep(i, n) rep(j, n) a[i*n + j] += b[i*n + j];
}

void subfrom(int* a, int* b, int n)
{ // Dregur fylkid |b| fra fylkinu |a|. Eins og `a -= b`.
	int i, j;
	rep(i, n) rep(j, n) a[i*n + j] -= b[i*n + j];
}

void multo(int* a, int* b, int n)
{ // Eins og `a *= b`.
	int i, j, k, c[n][n];
	rep(i, n) rep(j, n) c[i][j] = 0;
	rep(i, n) rep(j, n) rep(k, n) c[i][j] += a[i*n + k]*b[k*n + j];
	rep(i, n) rep(j, n) a[i*n + j] = c[i][j];
}

#if 0
3
1 2 3
4 5 6
7 8 9
9 8 7
6 5 4
3 2 1
#endif
int main()
{
	int i, j, n;
	scanf("%d", &n);
	int a[n][n], b[n][n];
	rep(i, n) rep(j, n) scanf("%d", &a[i][j]);
	rep(i, n) rep(j, n) scanf("%d", &b[i][j]);

	addto(*a, *b, n);
	printf("A + B:\n");
	rep(i, n) { rep(j, n) printf("%3d ", a[i][j]); printf("\n"); }
	subfrom(*a, *b, n); //andhverfa adgerdarinnar a undan
	subfrom(*a, *b, n);
	printf("A - B:\n");
	rep(i, n) { rep(j, n) printf("%3d ", a[i][j]); printf("\n"); }
	addto(*a, *b, n); //andhverfa adgerdarinnar a undan
	multo(*a, *b, n);
	printf("A*B:\n");
	rep(i, n) { rep(j, n) printf("%3d ", a[i][j]); printf("\n"); }
}
