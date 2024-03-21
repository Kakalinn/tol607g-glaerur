from random import randrange
def miller_rabin(n, k):
    if n%2 == 0: return n == 2
    if n <= 3: return n == 3
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

n = int(input())
r = 2
while not miller_rabin(r, 10) or n%r == 0: r += 1
print(r)


