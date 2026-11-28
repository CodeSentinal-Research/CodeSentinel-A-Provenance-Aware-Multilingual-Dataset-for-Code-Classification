s = input().strip()
from collections import Counter
c = Counter(s)
for i, ch in enumerate(s):
    if c[ch] == 1:
        print(i)
        break
else:
    print(-1)
