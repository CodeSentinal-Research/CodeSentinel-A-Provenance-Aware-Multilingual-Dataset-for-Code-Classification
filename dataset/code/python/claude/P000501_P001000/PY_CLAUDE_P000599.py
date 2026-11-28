
n=int(input());a=list(map(int,input().split()))
from collections import Counter;cnt=Counter(a)
res=[v for v in a if cnt[v]==1]
print(*res if res else [''])
