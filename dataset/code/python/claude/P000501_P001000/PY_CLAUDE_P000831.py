
n=int(input());bd=list(map(int,input().split()));m=int(input());k=int(input())
import math
def ok(day):
    bouquets=sum((v<=day)//k for v in (sum(1 for x in bd if x<=day for _  in [1]),))
    bloomed=[1 if x<=day else 0 for x in bd]
    b=cnt=0
    for v in bloomed:
        if v: cnt+=1
        else: cnt=0
        b+=cnt//k;cnt%=k
    return b>=m
lo,hi=min(bd),max(bd)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo if ok(lo) else -1)
