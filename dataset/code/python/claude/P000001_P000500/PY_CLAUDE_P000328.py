
from collections import Counter
s=input();cnt=Counter(s)
for i,c in enumerate(s):
    if cnt[c]==1: print(i);exit()
print(-1)
