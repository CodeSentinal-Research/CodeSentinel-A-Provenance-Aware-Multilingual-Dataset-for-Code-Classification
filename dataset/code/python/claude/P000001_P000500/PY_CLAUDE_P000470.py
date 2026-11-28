
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<hi:
    mid=(lo+hi)//2
    if a[mid]<x: lo=mid+1
    else: hi=mid

if lo>0 and abs(a[lo-1]-x)<abs(a[lo]-x): lo-=1
print(a[lo])
