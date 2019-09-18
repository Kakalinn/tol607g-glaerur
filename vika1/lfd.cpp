#include <iostream>

int main()
{
	int i, t, n, r;
	std::cin >> t;
	while (t-- != 0)
	{
		std::cin >> n;
		r = 1;
		for (i = 1; i <= n; ++i)
		{
			r *= i;
			r %= 10;
		}
		std::cout << r << std::endl;
	}
	return 0;
}
