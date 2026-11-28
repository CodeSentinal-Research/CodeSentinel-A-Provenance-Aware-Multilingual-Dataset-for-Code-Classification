
n=int(input());houses=list(map(int,input().split()));m=int(input());heaters=sorted(map(int,input().split()))
from bisect import bisect_left
ans=0
for h in houses:
    pos=bisect_left(heaters,h)
    d=float('inf')
    if pos<m: d=min(d,heaters[pos]-h)
    if pos>0: d=min(d,h-heaters[pos-1])
    ans=max(ans,d)
print(ans)
