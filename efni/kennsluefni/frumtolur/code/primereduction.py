from math import gcd
from random import randrange

def miller_rabin(n, k = 0):
    if n%2 == 0: return n == 2
    if n <= 3: return n == 3
    s, d, t = 0, n - 1, [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
    for _ in range(k): t.append(randrange(n - 2) + 1)
    while d%2 == 0: d, s = d//2, s + 1
    for a in t:
        if a > n - 2: continue
        if (x := pow(a, d, n)) in [1, n - 1]: continue
        for _ in range(s - 1):
            if (x := (x*x)%n) == n - 1: break
        else: return False
    return True

def rho(n):
    s, a = [2, 3, 4, 5, 7, 11, 13, 1031], 1
    f = lambda x: (x*x + a)%n
    while True:
        for x in s:
            y, d = x, 1
            while d == 1: x, y = f(x), f(f(y)); d = gcd(abs(x - y), n)
            if d != n: return [d, n//d]
        a += 1

def pollard_rho(n):
    a, s, p = [], [], [2, 3, 5, 7, 11, 13]
    for e in p:
        while n%e == 0: n //= e; a.append(e)
    if n == 1: return a
    s.append(n)
    while len(s) > 0:
        if miller_rabin(k := s.pop()): a.append(k)
        else: s += rho(k)
    return a




n = int(input())
while n != 4:
    r, l = 0, []
    while len(l) != 1:
        r += 1
        l = pollard_rho(n)
        n = sum(l)
    print(l[0], r)
    n = int(input())
    

