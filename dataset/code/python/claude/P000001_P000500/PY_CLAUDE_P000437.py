
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi,res=-1,n-1,-1
while 0<=hi and lo<=hi:
    mid=(lo+hi)//2
    if a[mid]<=x: res=a[mid];lo=mid+1
    else: hi=mid-1
lo=0
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]<=x: res=a[mid];lo=mid+1
    else: hi=mid-1
print(res)
