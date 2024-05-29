class stree:
    def __init__(T, n):
        T.p, T.n = [0]*2*n, n

    def query(T, x, y): # Reiknar summun yfir [x, y].
        x, y, r = x + n, y + n + 1, 0
        while x < y:
            r += (x%2)*T.p[x] + (y%2)*T.p[y - 1]
            x, y = x//2 + x%2, y//2
        return r

    def update(T, x, z): # Bætir z við x-ta stakið.
        T.p[x := x + n] += z
        while x > 1:
            T.p[x//2] = T.p[x] + T.p[x^1]
            x //= 2

#####
# Allt hér fyrir neðan er bara til að prófa
#####
from random import randrange
def slow(a, i, j):
    r = 0
    while i <= j: r += a[i]; i += 1
    return r

n, q = 100, 100
p = stree(n)
a = [0]*n
for _ in range(q):
    x, y = randrange(n), randrange(2*10**9) - 10**9
    p.update(x, y)
    a[x] += y
    for i in range(n):
        for j in range(i):
            assert p.query(j, i) == slow(a, j, i)

