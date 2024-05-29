import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;

public class miller_rabin
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.println(miller_rabin(s.nextLong()));
    }

    static long bigprod(long x, long y, long m)
    {
        BigInteger r = BigInteger.valueOf(x);
        r = r.multiply(BigInteger.valueOf(y));
        r = r.mod(BigInteger.valueOf(m));
        return r.longValue();
    }
    static long modpow(long x, long n, long m)
    {
        long r;
        for (r = 1; n > 0; n = n/2, x = bigprod(x, x, m)) if (n%2 == 1) r = bigprod(r, x, m);
        return r; 
    }
    static boolean miller_rabin(long n)
    {
        if (n%2 == 0) return n == 2;
        if (n <= 3) return n == 3;
        long a, x, i, s = 0, d = n - 1;
        long[] t = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
        while (d%2 == 0) { d /= 2; s++; }
        for (int k = 0; k < t.length; k++) if (t[k] <= n - 2)
        {
            a = t[k]; x = modpow(a, d, n);
            if (x == 1 || x == n - 1) continue;
            for (i = 0; i < s - 1; i++) if ((x = bigprod(x, x, n)) == n - 1) break;
            if (i == s - 1) return false;
        }
        return true;
    }
}
