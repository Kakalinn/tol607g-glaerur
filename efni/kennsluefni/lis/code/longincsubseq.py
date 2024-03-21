from bisect import bisect

def lis(a, weakly_increasing = True):
    INF = 2**32
    s = 0 if weakly_increasing else -1
    e, d = [INF]*(len(a) + 1), [INF]*(len(a) + 1)
    d[0] = -INF
    for i in range(len(a)):
        r = bisect(d, a[i] + s, 0, len(d))
        d[r], e[i] = a[i], d[r - 1]
    while d[-1] == INF: d.pop()
    i, j, y = len(a) - 1, len(d) - 1, d[-1]
    while j > 0:
        if a[i] == y: y, d[j] = e[i], i; j -= 1
        i -= 1
    return d[1:]

while True:
    try: n = int(input())
    except EOFError: break
    l = lis(list(map(int, input().split())), False)
    print(len(l))
    print(*l)
