def check(n, x):                                                                # Fall sem ákvarðar hvort a og b innihaldi sömu tölustafi með því að
    return "".join(sorted(list(str(n)))) != "".join(sorted(list(str(x))))       #   breyta tölunum í lista af stöfum, raða þeim og breyta svo í strengi.

n = int(input())                                                                # Innlestur.
x = n + 1
while x < 10**6 and check(n, x): x += 1                                         # Prófum allar mögulegar tölur stærri en n.
if x == 10**6: print(0)
else: print(x)                                                                  # Prentum svarið ef við fundum eitthvað.
