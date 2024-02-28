import java.util.Scanner;
import java.util.Arrays;

public class lis
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        int i, n = s.nextInt();
        int[] a = new int[n];
        
        for (i = 0; i < n; i++) a[i] = s.nextInt();
        int[] b = lis(a);
        System.out.println(b.length);
        for (i = 0; i < b.length; i++) System.out.print(b[i] + " ");
        System.out.println();
    }

    static int[] lis(int[] a)
    {
        int i, j, x, y, r, s, n = a.length, INF = 1 << 30;
        int[] d = new int[n + 1];
        int[] e = new int[n];
        for (i = 0; i < n + 1; i++) d[i] = i == 0 ? -INF : INF;
        for (i = 0; i < n; i++)
        {
            r = Arrays.binarySearch(d, a[i]);
            if (r < 0) r = -r - 1;
            d[r] = a[i];
            e[i] = d[r - 1];
        }
        for (x = n; d[x] == INF; x--);
        int[] b = new int[x];
        for (i = n - 1, j = x - 1, y = d[x]; j >= 0; i--) if (a[i] == y)
        {
            y = e[i];
            b[j--] = a[i];
        }
        return b;
    }
}
