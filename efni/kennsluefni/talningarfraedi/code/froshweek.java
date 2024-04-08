import java.util.Scanner;

public class froshweek
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = s.nextInt();
        System.out.println(teljum_umhverfingar(a));
    }

    static long teljum_umhverfingar(int[] a)
    {
        long z = 0;
        long[][] b = new long[2][a.length];
        for (int i = 0; i < a.length; i++) b[0][i] = a[i];
        for (int e = 1, t = 0; e < a.length; e *= 2, t = 1 - t) for (int l = 0; l < a.length; l += 2*e)
        {
            int i = l, c = l, j = Math.min(l + e, a.length), m = Math.min(l + e, a.length), r = Math.min(l + 2*e, a.length);
            while (i < m || j < r)
                if (i == m || (j < r && b[t][j] < b[t][i])) { z += m - i; b[1 - t][c++] = b[t][j++]; }
                else b[1 - t][c++] = b[t][i++];
        }
        return z;
    }
}
