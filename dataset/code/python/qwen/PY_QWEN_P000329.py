s = input().strip()
t = input().strip()
from collections import Counter
sc = Counter(s)
tc = Counter(t)
for k in tc:
    if tc[k] > sc[k]:
        print(k)
        break
