
e,f=int(input()),int(input())
from functools import lru_cache
@lru_cache(None)
def dp(eggs,floors):
    if eggs==1 or floors<=1: return floors
    lo,hi=1,floors
    while lo<hi:
        mid=(lo+hi)//2
        broken=dp(eggs-1,mid-1);safe=dp(eggs,floors-mid)
        if broken<safe: lo=mid+1
        else: hi=mid
    return 1+min(dp(eggs-1,lo-1),dp(eggs,floors-lo))
print(dp(e,f))
