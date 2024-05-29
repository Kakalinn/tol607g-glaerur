import java.util.Scanner;

public class biltre
{
    public static void main(String[] args)
    {
        Scanner io = new Scanner(System.in);
        int n = io.nextInt(), q = io.nextInt();
        stree p = new stree(n);
        for (int i = 0; i < q; i++)
        {
            int t = io.nextInt(), x = io.nextInt(), y = io.nextInt();
            if (t == 1) p.update(x, y);
            else System.out.println(p.query(x, y));
        }
    }
}

class stree
{
    int[] p, o;

    public stree(int n)
    {
        p = new int[5*n];
        p[0] = n;
    }
    static int LEFT(int x) { return x*2; }
    static int RIGHT(int x) { return x*2 + 1; }

    int qrec(int i, int j, int x, int y, int e)
    {
        if (x == i && y == j) return p[e];
        int m = (i + j)/2;
        if (y <= m) return qrec(i, m, x, y, LEFT(e));
        else if (x > m) return qrec(m + 1, j, x, y, RIGHT(e));
        return qrec(i, m, x, m, LEFT(e)) + qrec(m + 1, j, m + 1, y, RIGHT(e));
    }
    int query(int x, int y)
    {
        if (y < x) return 0;
        return qrec(0, p[0] - 1, x, y, 1);
    }

    void urec(int i, int j, int x, int z, int e)
    {
        p[e] += z;
        if (j == i) return;
        int m = (i + j)/2;
        if (x <= m) urec(i, m, x, z, LEFT(e));
        else urec(m + 1, j, x, z, RIGHT(e));
    }
    void update(int x, int z)
    {
        urec(0, p[0] - 1, x, z, 1);
    }
}
