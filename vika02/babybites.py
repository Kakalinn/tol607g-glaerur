n = int(input())
l = input().split()
f = True
for i in range(n):
    if l[i] != 'mumble' and l[i] != str(i + 1):
        f = False
        break
if f: print('jebb')
else: print('neibb')
