
from collections import Counter;s=input();cnt=Counter(s)
res=-1
for i,c in enumerate(s):
    if cnt[c]==1: res=c
print(res)
