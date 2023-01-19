from math import gcd
from random import randrange

def miller_rabin(n, k):
    if n%2 == 0:
        return n == 2
    if n <= 3:
        return n == 3
    s = 0
    d = n - 1
    t = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41]
    for _ in range(k): t.append(randrange(n - 2) + 1)
    while d%2 == 0:
        d //= 2
        s += 1
    for a in t:
        if a > n - 2: continue
        x = pow(a, d, n);
        if x == 1 or x == n - 1: continue
        e = True
        for i in range(s - 1):
            x = (x*x)%n
            if x == n - 1:
                e = False
                break
        if e: return False;
    return True;
def rho(n):
    s = [2, 3, 4, 5, 7, 11, 13, 1031]
    a = 1
    while True:
        for x in s:
            y = x
            d = 1
            while d == 1:
                x = (x*x + a)%n
                y = (y*y + a)%n
                y = (y*y + a)%n
                d = gcd(abs(x - y), n)
            if d != n: return d
        a += 1

def pollard_rho(n):
    a = []
    s = []
    p = [2, 3, 5, 7, 11, 13];
    for e in p:
        while n%e == 0:
            n //= e
            a.append(e)
    if n == 1: return a
    s.append(n)
    while (len(s) > 0):
        k = s[-1]
        del(s[-1])
        if miller_rabin(k, 10):
            a.append(k)
        else:
            r = rho(k);
            s.append(r)
            s.append(k//r)
    return a

print(pollard_rho(int(input())))

