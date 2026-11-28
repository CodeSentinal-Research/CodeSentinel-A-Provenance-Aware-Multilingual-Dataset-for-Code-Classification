
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi=0,n-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==x: print(mid);exit()
    if a[lo]<=a[mid]:
        if a[lo]<=x<a[mid]: hi=mid-1
        else: lo=mid+1
    else:
        if a[mid]<x<=a[hi]: lo=mid+1
        else: hi=mid-1
print(-1)
