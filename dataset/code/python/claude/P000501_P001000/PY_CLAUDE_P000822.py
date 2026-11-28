
n=int(input());a=list(map(int,input().split()));k=int(input());x=int(input())
from bisect import bisect_left
pos=bisect_left(a,x)
lo,hi=max(0,pos-k),min(n-k,pos)
while lo<hi:
    mid=(lo+hi)//2
    if x-a[mid]>a[mid+k]-x: lo=mid+1
    else: hi=mid
print(*a[lo:lo+k])
