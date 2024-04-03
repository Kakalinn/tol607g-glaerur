
def teljum_umhverfingar(a):
    t, z, e, b = 0, 0, 1, [a.copy(), [0]*len(a)]
    while e < n:
        for l in range(0, n, e*2):
            i = c = l; j = m = min(l + e, n); r = min(l + 2*e, n)
            while i < m or j < r:
                if i == m or (j < r and b[t][j] < b[t][i]): z += m - i; b[1 - t][c] = b[t][j]; c += 1; j += 1
                else: b[1 - t][c] = b[t][i]; c += 1; i += 1
        e, t = e*2, 1 - t
    return z;

n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
print(teljum_umhverfingar(a))
