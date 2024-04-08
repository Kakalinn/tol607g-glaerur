import java.util.Scanner;

public class porpoises
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        for (int i = 0; i < n; i++)
        {
            long x = s.nextLong(), m = s.nextLong();
            System.out.println("" + x + " " + fib(m, 1000000000L));
        }
    }
    
    static long fib(long n, long m)
    {
        long[][] a = {{1, 1}, {1, 0}};
        if (n <= 2) return 1;
        matpow(a, n - 2, m);
        return (a[0][0] + a[0][1])%m;
    }

    static void multo(long[][] a, long[][] b, long m)
    { // a *= b
        long[][] c = new long[a.length][a.length];
        for (int i = 0; i < a.length; i++) for (int j = 0; j < a.length; j++) for (int k = 0; k < a.length; k++)
            c[i][j] = (c[i][j] + (a[i][k]*b[k][j])%m)%m;
        for (int i = 0; i < a.length; i++) for (int j = 0; j < a.length; j++) a[i][j] = c[i][j];
    }

    static void matpow(long[][] a, long p, long m)
    { // a = a^p
        long[][] r = {{1, 0}, {0, 1}};
        while (p > 0)
        {
            if (p%2 == 1) multo(r, a, m);
            p /= 2;
            multo(a, a, m);
        }
        for (int i = 0; i < a.length; i++) for (int j = 0; j < a.length; j++) a[i][j] = r[i][j];
    }
}

