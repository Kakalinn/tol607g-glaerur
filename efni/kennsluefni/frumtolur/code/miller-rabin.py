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

n = int(input())
print(miller_rabin(n))

