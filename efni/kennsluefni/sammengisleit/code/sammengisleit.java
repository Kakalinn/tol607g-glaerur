import java.util.Arrays;
public class sammengisleit
{
    public static void main(String[] args)
    {
        int n = 10;
        uf p = new uf(n);
        for (int i = 0; i < n; i++)
        {
            p.join(0, i);
            System.out.println(p.size(0));
        }
    }
}

class uf
{
    int[] p;
    public uf(int n)
    {
        p = new int[n];
        for (int i = 0; i < n; i++) p[i] = -1;
    }
    int find(int x) { return p[x] < 0 ? x : (p[x] = this.find(p[x])); }
    int size(int x) { return -p[this.find(x)]; }
    void join(int x, int y)
    {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (p[rx] > p[ry]) { p[ry] += p[rx]; p[rx] = ry; }
        else { p[rx] += p[ry]; p[ry] = rx; }
    }
}

