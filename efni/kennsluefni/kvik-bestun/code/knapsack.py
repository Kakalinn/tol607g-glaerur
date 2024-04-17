def knapsack(a, c):
    n = len(a)
    d = [[0 for _ in range(c + 1)] for _ in range(n + 1)]
    for i in range(n):
        for j in range(c + 1):
            d[i + 1][j] = max(d[i + 1][j], d[i][j])
            if j + a[i][1] <= c: d[i + 1][j + a[i][1]] = max(d[i + 1][j + a[i][1]], d[i][j] + a[i][0])
    j, i, r = c, n - 1, []
    while i >= 0:
        if j - a[i][1] >= 0 and d[i][j] < d[i][j - a[i][1]] + a[i][0]:
            j -= a[i][1]
            r.append(i)
        i -= 1
    return r[::-1]

n, c = map(int, input().split())
a = []
for _ in range(n):
    w, v = map(int, input().split())
    a.append((v, w))

l = knapsack(a, c)
print("Við veljum", len(l), "hluti:")
print("  ", l)
print("Samtals notum við", sum(map(lambda x: a[x][1], l)) , "rýmd")
print("  og fáum", sum(map(lambda x: a[x][0], l)) , "virði")

