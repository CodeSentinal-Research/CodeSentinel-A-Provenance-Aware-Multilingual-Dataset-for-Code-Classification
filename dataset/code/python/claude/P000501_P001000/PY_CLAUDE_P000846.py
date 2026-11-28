
n=int(input());m=int(input());q=list(map(int,input().split()))
import math
def ok(mx):
    return sum(math.ceil(x/mx) for x in q)<=n
lo,hi=1,max(q)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
