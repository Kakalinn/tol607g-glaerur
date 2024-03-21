import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;

public class pollard_rho
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        long[] r = pollard_rho(s.nextLong());
        for (int i = 0; i < r.length; i++) System.out.print(r[i] + " ");
        System.out.println();
    }

    static long modpow(long x, long n, long m)
    {
        long r;
        for (r = 1; n > 0; n = n/2, x = (x*x)%m) if (n%2 == 1) r = (r*x)%m;
        return r; 
    }
    static long gcd(long a, long b) { return b == 0 ? a : gcd(b, a%b); }
    static long bigprod(long x, long y, long m)
    {
        return BigInteger.valueOf(x).multiply(BigInteger.valueOf(y)).mod(BigInteger.valueOf(m)).longValue();
    }
    static boolean miller_rabin(long n)
    {
        if (n%2 == 0) return n == 2;
        if (n <= 3) return n == 3;
        long a, x, i, s = 0, d = n - 1;
        long[] t = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        while (d%2 == 0) { d /= 2; s++; }
        for (int k = 0; k < 12; k++) if (t[k] <= n - 2)
        {
            a = t[k]; x = modpow(a, d, n);
            if (x == 1 || x == n - 1) continue;
            for (i = 0; i < s - 1; i++) if ((x = bigprod(x, x, n)) == n - 1) break;
            if (i == s - 1) return false;
        }
        return true;
    }
    static long rho(long n)
    {
        long[] s = {2, 3, 4, 5, 7, 11, 13, 1031};
        long i, a, x, y, d;
        for (a = 1;; a++) for (int j = 0; j < 8; j++)
        {
            x = y = s[j]; d = 1;
            while (d == 1)
            {
                x = (bigprod(x, x, n) + a)%n;
                y = (bigprod(y, y, n) + a)%n;
                y = (bigprod(y, y, n) + a)%n;
                d = gcd(Math.abs(x - y), n);
            }
            if (d != n) return d;
        }
    }
    static long[] pollard_rho(long n)
    {
        int ss = 0, aa = 0;
        long[] s = new long[200], p = {2, 3, 5, 7, 11, 13}, a = new long[200];
        for (int i = 0; i < p.length; i++) while (n%p[i] == 0) { n /= p[i]; a[aa++] = p[i]; }
        if (n != 1) s[ss++] = n;
        while (ss > 0)
        {
            long k = s[--ss];
            if (miller_rabin(k)) a[aa++] = k;
            else { long r = rho(k); s[ss++] = r; s[ss++] = k/r; }
        }
        return Arrays.copyOf(a, aa);
    }
}
