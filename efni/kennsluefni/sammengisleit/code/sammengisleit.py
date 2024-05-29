import sys
sys.setrecursionlimit(10**5)

def join(p, x, y):
    rx, ry = find(p, x), find(p, y)
    if rx == ry: return
    if p[rx] > p[ry]: p[ry], p[rx] = p[ry] + p[rx], ry
    else: p[rx], p[ry] = p[rx] + p[ry], rx
    
def find(p, x):
    if p[x] < 0: return x
    p[x] = find(p, p[x])
    return p[x]

def size(p, x): return -p[find(p, x)];
def init(n): return [-1]*n

n = 10
p = init(n)
for i in range(n):
    join(p, 0, i)
    print(size(p, 0))
