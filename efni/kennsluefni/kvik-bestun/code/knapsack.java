import java.util.Scanner;
public class knapsack
{
    public static void main(String[] args)
    {
        Scanner io = new Scanner(System.in);
        int n = io.nextInt(), c = io.nextInt(), x = 0;
        int[] w = new int[n], v = new int[n];
        for (int i = 0; i < n; i++) { w[i] = io.nextInt(); v[i] = io.nextInt(); }
        int[] r = knapsack(v, w, n, c);

        int t = 0, s = 0;
        for (int i = 0; i < r.length; i++) s += r[i];
        System.out.println("Við veljum " + s + " hluti");
        System.out.print("  ");
        s = 0;
        for (int i = 0; i < r.length; i++)
        {
            t += r[i]*v[i];
            s += r[i]*w[i];
            if (r[i] == 1) System.out.print(i + " ");
        }
        System.out.println();
        System.out.println("Samtals notum við " + s + " rýmd");
        System.out.println("  og fáum " + t + " virði");
    }

    static int d[][];
    static int dp_lookup(int x, int y, int[] v, int[] w)
    {
        if (y < 0) return -(1 << 30);
        if (x < 0) return 0;
        if (d[x][y] != -1) return d[x][y];
        return d[x][y] = Math.max(dp_lookup(x - 1, y, v, w),
                dp_lookup(x - 1, y - w[x], v, w) + v[x]);
    }

    static int[] knapsack(int[] v, int[] w, int n, int c)
    {
        d = new int[n][c + 1];
        int[] r = new int[n];
        for (int i = 0; i < n; i++) for (int j = 0; j <= c; j++) d[i][j] = -1;
        for (int j = c, i = n - 1; i >= 0; i--)
            if (dp_lookup(i - 1, j, v, w) < dp_lookup(i - 1, j - w[i], v, w) + v[i])
            {
                j -= w[i];
                r[i] = 1;
            }
        return r;
    }
}
