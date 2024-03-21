import java.util.Scanner;
import java.util.Arrays;
import java.math.*;

public class jazzitup
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        long i, n = s.nextLong();
        for (i = 2; !miller_rabin(i) || n%i == 0; i++);
        System.out.println(i);
    }

    static long modpow(long x, long n, long m)
    {
        long r;
        for (r = 1; n > 0; n = n/2, x = (x*x)%m) if (n%2 == 1) r = (r*x)%m;
        return r; 
    }
    static long bigprod(long x, long y, long m)
    {
        return BigInteger.valueOf(x).multiply(BigInteger.valueOf(y)).mod(BigInteger.valueOf(m)).longValue();
    }
    static boolean miller_rabin(long n)
    {
        if (n%2 == 0) return n == 2;
        if (n <= 3) return n == 3;
        long a, x, i, s = 0, d = n - 1;
        long[] t = {2L, 3L, 5L, 7L, 11L, 13L, 17L, 19L, 23L, 29L, 31L, 37L};
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
}
