import java.util.*;

public class lfd
{
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- != 0)
		{
			int n = s.nextInt();
			int r = 1;
			for (int i = 1; i <= n; i++)
			{
				r *= i;
				r %= 10;
			}
			System.out.println(r);
		}
	}
}
