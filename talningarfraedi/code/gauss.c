#include <stdio.h>
#include <assert.h>
#include <math.h>
#define rep(E, F) for (E = 0; E < (F); E++)

int gauss(double* a, int s, int n, int m)
{ // Her er |a| |n|x|m| fylki. Gauss eyding er framkvaemd upp ad dalki |s|.
	int i, j, k, t, r = 0;
	rep(i, n)
	{
		t = -1;
		while (++t < s && fabs(a[i*m + t]) < 1e-9);
		if (t == s) continue;
		r++;
		for (j = m - 1; j >= t; j--) a[i*m + j] = a[i*m + j]/a[i*m + t];
		rep(j, n) if (i != j) for (k = m - 1; k >= t; k--)
			a[j*m + k] = a[j*m + k] - a[i*m + k]*a[j*m + t];
	}
	return r;
}

void multo(double* a, double* b, int n)
{ // Eins og `a *= b`.
	int i, j, k;
	double c[n][n];
	rep(i, n) rep(j, n) c[i][j] = 0;
	rep(i, n) rep(j, n) rep(k, n) c[i][j] += a[i*n + k]*b[k*n + j];
	rep(i, n) rep(j, n) a[i*n + j] = c[i][j];
}

void inverse(double* p, int n)
{ //Eftir kallid er |a| ordid andhverfan sin.
	double a[n][2*n], b[n][n], c[n][n];
	int i, j, k;
	rep(i, n) rep(j, n) c[i][j] = a[i][j] = p[i*n + j];
	rep(i, n) rep(j, n) a[i][j + n] = 0.0;
	rep(i, n) a[i][i + n] = 1.0;
	printf(">> %d\n", gauss(*a, n, n, 2*n));
	rep(i, n)
	{
		rep(j, n) if (fabs(a[i][j] - 1.0) < 1e-9) break;
		rep(k, n) p[j*n + k] = a[i][k + n];
	}
	rep(i, n) rep(j, n) b[i][j] = p[i*n + j];
	multo(*b, *c, n);
	rep(i, n) rep(j, n) assert(fabs(b[i][j] - (i == j ? 1.0 : 0.0)) < 1e-9);
}

int main()
{
	int i, j, n;
	scanf("%d", &n);
	double a[n][n];
	rep(i, n) rep(j, n) scanf("%lf", &a[i][j]);
	inverse(*a, n);
	rep(i, n) { rep(j, n) printf("%3.3f ", a[i][j]); printf("\n"); }
	return 0;
}
