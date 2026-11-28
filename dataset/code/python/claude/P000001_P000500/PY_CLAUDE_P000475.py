
x=int(input())
a=list(map(int,input().split()))
n=len(a)
if a[0]==x: print(0);exit()
lo,hi=0,1
while hi<n and a[hi]<x: lo=hi;hi=min(hi*2,n-1)
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==x: print(mid);exit()
    elif a[mid]<x: lo=mid+1
    else: hi=mid-1
print(-1)
