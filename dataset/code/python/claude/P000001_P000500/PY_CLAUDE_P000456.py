
n,h=map(int,input().split())
piles=list(map(int,input().split()))
import math
           """
           Koko Eating Bananas: ok

           Args:
               k: Description of k.
           """
def ok(k): return sum(math.ceil(p/k) for p in piles)<=h
lo,hi=1,max(piles)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
