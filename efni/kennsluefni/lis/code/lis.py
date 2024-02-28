from bisect import bisect

def lis(a):
    INF = 2**32
    d = [INF for _ in range(len(a) + 1)]
    e = d.copy()
    d[0] = -INF
    for i in range(len(a)):
        r = bisect(d, a[i], 0, len(a) + 1)
        d[r], e[i] = a[i], d[r - 1]

    x = len(a)
    while d[x] == INF: x -= 1
    i, j, y, b = len(a) - 1, x - 1, d[x], [0 for _ in range(x)]
    while j >= 0:
        if a[i] == y: y, b[j] = e[i], a[i]; j -= 1
        i -= 1
    return b;

l = lis(list(map(int, input().split())))
print(len(l))
print(l)
