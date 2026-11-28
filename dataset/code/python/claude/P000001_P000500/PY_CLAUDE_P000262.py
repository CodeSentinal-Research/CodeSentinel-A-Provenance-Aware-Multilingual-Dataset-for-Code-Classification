
from collections import Counter;s=input();cnt=Counter(s)
for c in s:
    if cnt[c]==1: print(c);exit()
print(-1)
