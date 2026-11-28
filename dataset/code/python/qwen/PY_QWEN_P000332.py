order = input().strip()
s = input().strip()
from collections import Counter
c = Counter(s)
res = []
for ch in order:
    if ch in c:
        res.append(ch * c[ch])
        del c[ch]
for ch in c:
    res.append(ch * c[ch])
print("".join(res))
