#include <bits/stdc++.h>
using namespace std;

void sort(int *a, int n)
{
	int i, j, mn;
	priority_queue<int> q;
	for (i = 0; i < n; i++) q.push(-a[i]);
	for (i = 0; i < n; i++) a[i] = -q.top(), q.pop();
}

int main()
{
	int i, n;
	cin >> n;
	int a[n];
	for (i = 0; i < n; i++) cin >> a[i];
	sort(a, n);
	for (i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	return 0;
}
