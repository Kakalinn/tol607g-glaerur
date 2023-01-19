def check(n, x):
    return "".join(sorted(list(str(n)))) != "".join(sorted(list(str(x))))

n = int(input())
x = n + 1
while x < 10**6 and check(n, x): x += 1
if x == 10**6: print(0)
else: print(x)
