#include <stdio.h>
#include <assert.h>
#define rep(E, F) for (E = 0; E < (F); E++)
int get_int();
double get_double();
int get_string(char* b, char t);
int r[3][1000];
int foo(int* a, int n)
{
    int i, j, b[3][n], c[3] = {0, 0, 0};
    rep(i, n) rep(j, 3) b[j][i] = 0;
    i = 0;
    while (i < n && a[i] == 1) b[0][i++] = 1, c[0]++;
    while (i < n && a[i] == 2) b[0][i] = 1, b[1][i] = 1, i++, c[0]++, c[1]++;
    while (i < n && a[i] == 1) b[1][i++] = 1, c[1]++;
    while (i < n && a[i] == 2) b[1][i] = 1, b[2][i] = 1, i++, c[1]++, c[2]++;
    while (i < n && a[i] == 1) b[2][i++] = 1, c[2]++;
    if (c[2] == 0 && c[1] == 0)
    {
        if (n == 2) return 0;
        b[1][0] = b[2][1] = 1;
        b[0][0] = b[0][1] = 0;
    }
    else if (c[2] == 0)
    {
        rep(i, n) if (a[i] == 2) break;
        b[2][i] = 1;
    }
    rep(i, n) if (b[0][i] == 0 && b[1][i] == 0 && b[2][i] == 0) return 0;
    rep(j, 3) rep(i, n) r[j][i] = b[j][i] ? 'A' + j : '.';
    return 1;
}

int main()
{
    int i, j, x, y, z, w, n = get_int(), m = get_int();
    int a[n][m], b[n][m], c[n][m];
    rep(i, n) { rep(j, m) a[i][j] = getchar() - '0'; getchar(); }
    if (n == 1 && m == 1)
    {
        if (a[0][0] == 1) { printf("impossible\n"); return 0; }
        printf("A\n\nB\n\nC\n");
        return 0;
    }
    if (n == 1)
    {
        int g[m];
        rep(i, m) g[i] = a[0][i];
        if (!foo(g, m)) { printf("impossible\n"); return 0; }
        rep(x, 3) { rep(i, m) printf("%c", r[x][i]); printf("\n\n"); }
        return 0;
    }
    if (m == 1)
    {
        int g[n];
        rep(i, n) g[i] = a[i][0];
        if (!foo(g, n)) { printf("impossible\n"); return 0; }
        rep(x, 3) { rep(i, n) printf("%c\n", r[x][i]); printf("\n"); }
        return 0;
    }
    rep(i, n) rep(j, m) b[i][j] = 1;
    rep(i, n) b[i][0] = 2;
    z = n - 1, w = m - 3, x = n, y = m - 1;
    while (1)
    {
        if (z <= 0) break;
        rep(i, z) b[--x][y] = 0;
        z -= 2;
        if (w <= 0) break;
        rep(i, w) b[x][--y] = 0;
        w -= 2;
        if (z <= 0) break;
        rep(i, z) b[++x][y] = 0;
        z -= 2;
        if (w <= 0) break;
        rep(i, w) b[x][++y] = 0;
        w -= 2;
    }
    rep(i, n) rep(j, m) c[i][j] = -1;
    rep(i, n) rep(j, m)
    {
        if (i > 0 && b[i - 1][j] != b[i][j]) c[i][j] = b[i - 1][j];
        if (j > 0 && b[i][j - 1] != b[i][j]) c[i][j] = b[i][j - 1];
        if (i < n - 1 && b[i + 1][j] != b[i][j]) c[i][j] = b[i + 1][j];
        if (j < m - 1 && b[i][j + 1] != b[i][j]) c[i][j] = b[i][j + 1];
    }
    //rep(i, n) { rep(j, m) printf("%d ", a[i][j]); printf("\n"); } printf("\n");
    //rep(i, n) { rep(j, m) printf("%d ", b[i][j]); printf("\n"); } printf("\n");
    //rep(i, n) { rep(j, m) printf("%d ", c[i][j]); printf("\n"); } printf("\n");
    rep(i, n) rep(j, m) assert(c[i][j] != -1);
    rep(x, 3)
    {
        rep(i, n)
        {
            rep(j, m) printf("%c",
					(b[i][j] == x || (a[i][j] == 2 && c[i][j] == x))
					? 'A' + x : '.');
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

int get_string(char* b, char t)
{
    int i = 0; b[i++] = getchar();
    while (b[i - 1] != t) b[i++] = getchar();
    b[i - 1] = '\0';
    return i - 1;
}

int get_int()
{
    int sgn = 1, ret = 0;
    char c  = getchar();
    while (1)
    {
        if (c == EOF) return EOF;
        if (c >= '0' && c <= '9') break;
        if (c == '-')
        {
            c = getchar();
            if (c < '0' || c > '9') continue;
            sgn = -1;
            break;
        }
        c = getchar();
    }

    while (1)
    {
        ret = ret*10 + c - '0';
        c = getchar();
        if (c < '0' || c > '9') return sgn*ret;
    }
}

double get_double()
{
    double ret = 0;
    char c     = getchar();
    int sgn;

    while (1)
    {
        if (c == EOF)
        {
            return EOF;
        }
        if (c >= '0' && c <= '9')
        {
            sgn = 1;
            break;
        }
        if (c == '-')
        {
            c = getchar();

            if (c < '0' || c > '9')
            {
                continue;
            }

            sgn = -1;
            break;
        }
        c = getchar();
    }

    while (1)
    {
        ret = ret*10 + c - '0';

        c = getchar();

        if (c == '.')
        {
            double pos = 0.1;

            c = getchar();
            while (c >= '0' && c <= '9')
            {
                ret += pos*(c - '0');
                pos /= 10;
                c = getchar();
            }

            return sgn*ret;
        }
        else if (c < '0' || c > '9')
        {
            return sgn*ret;
        }
    }
}

