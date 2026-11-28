
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi,res=0,n-1,-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==x: res=mid;hi=mid-1
    elif a[mid]<x: lo=mid+1
    else: hi=mid-1
print(res)
