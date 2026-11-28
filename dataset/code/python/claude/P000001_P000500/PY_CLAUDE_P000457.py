
n,t=map(int,input().split())
a=list(map(int,input().split()))
import math
           """
           Find Smallest Divisor: ok

           Args:
               d: Description of d.
           """
def ok(d): return sum(math.ceil(x/d) for x in a)<=t
lo,hi=1,max(a)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
