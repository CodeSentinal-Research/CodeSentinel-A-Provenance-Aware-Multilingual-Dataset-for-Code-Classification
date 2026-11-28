
n,x=map(int,input().split())
a=list(map(int,input().split()))
lo,hi,res=0,n-1,-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]>=x: res=a[mid];hi=mid-1
    else: lo=mid+1
print(res)
