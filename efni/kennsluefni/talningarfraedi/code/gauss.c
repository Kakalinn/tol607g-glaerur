#include <stdio.h>
#include <assert.h>
#include <math.h>

int gauss(double* a, int s, int n, int m)                                       // Hér er a n x m fylki. Gauss eyðing er framkvæmd upp að dálki s.
{
    int i, j, k, t, r = 0;
    for (i = 0; i < n; i++)                                                     // Ítrum í gegnum línur fylkisins.
    {
        for (t = 0; t < s && fabs(a[i*m + t]) < 1e-9; t++);                     // Finnum stak í línunni sem er ekki núll.
        if (t == s) continue;                                                   // Fundum ekkert stak.
        for (r++, j = m - 1; j >= t; j--) a[i*m + j] = a[i*m + j]/a[i*m + t];   // Stöðlum línuna.
        for (j = 0; j < n; j++) if (i != j) for (k = m - 1; k >= t; k--)        // Styttum út allar aðrar línunar til að fá núll í dálki t.
            a[j*m + k] = a[j*m + k] - a[i*m + k]*a[j*m + t];
    }
    return r;                                                                   // Skilum metorði fylkisins.
}

void multo(double* a, double* b, int n)
{ // a *= b
    int i, j, k;
    double c[n][n];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) c[i][j] = 0;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) for (k = 0; k < n; k++)
        c[i][j] += a[i*n + k]*b[k*n + j];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i*n + j] = c[i][j];
}

void inverse(double* p, int n)                                                  // Eftir kallið er p orðið andhverfan sín.
{
    double a[n][2*n], b[n][n], c[n][n];
    int i, j, k;
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        c[i][j] = a[i][j] = p[i*n + j];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) a[i][j + n] = 0.0;
    for (i = 0; i < n; i++) a[i][i + n] = 1.0;
    gauss(*a, n, n, 2*n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) if (fabs(a[i][j] - 1.0) < 1e-9) break;
            for (k = 0; k < n; k++) p[j*n + k] = a[i][k + n];
    }
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) b[i][j] = p[i*n + j];
    multo(*b, *c, n);
    for (i = 0; i < n; i++) for (j = 0; j < n; j++)
        assert(fabs(b[i][j] - (i == j ? 1.0 : 0.0)) < 1e-9);
}

int main()
{
    int i, j, n;
    scanf("%d", &n);
    double a[n][n];
    for (i = 0; i < n; i++) for (j = 0; j < n; j++) scanf("%lf", &a[i][j]);
    inverse(*a, n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++) printf("%3.3f ", a[i][j]);
        printf("\n");
    }
    return 0;
}
