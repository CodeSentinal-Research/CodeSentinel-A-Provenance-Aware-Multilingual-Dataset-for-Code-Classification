
from collections import Counter
n=int(input());a=list(map(int,input().split()))
cnt=Counter(a);res=[v for v in a if cnt[v]==1]
print(*res if res else [''])
