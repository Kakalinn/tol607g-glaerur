n = int(input())                                                                # Innlestur hefst.
a = list(map(int, input().split()))                                             # Innlestri lokið.
b = [[a[i], i] for i in range(n)]                                               # Búum til lista af tvenndum.
b.sort(key = lambda x: x[0])                                                    # Röðum tvenndunum eftir fyrra stakinu.
for i in range(n): b[i][0] = i                                                  # Þjöppum nú hnitunum.
b.sort(key = lambda x: x[1])                                                    # Röðum eftir seinna hnitinu.
for i in range(n): a[i] = b[i][0]                                               # Þjöppum hnitunum í upprunarlega listanum.
print(*a)                                                                       # Prentum listann.
