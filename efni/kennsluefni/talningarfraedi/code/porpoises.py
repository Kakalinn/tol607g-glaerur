def fib(n, m):
    f = lambda x, y: \
        [[(x[0][0]*y[0][0] + x[0][1]*y[1][0])%m, (x[0][0]*y[0][1] + x[0][1]*y[1][1])%m], \
        [(x[1][0]*y[0][0] + x[1][1]*y[1][0])%m, (x[1][0]*y[0][1] + x[1][1]*y[1][1])%m]]
    if n <= 2: return 1
    a, r = [[1, 1], [1, 0]], [[1, 0], [0, 1]]
    n -= 2
    while n > 0:
        if n%2 == 1: r = f(r, a)
        n, a = n//2, f(a, a)
    return (r[0][0] + r[0][1])%m

n = int(input())
for _ in range(n):
    x, n = map(int, input().split())
    print(x, fib(n, 10**9))

