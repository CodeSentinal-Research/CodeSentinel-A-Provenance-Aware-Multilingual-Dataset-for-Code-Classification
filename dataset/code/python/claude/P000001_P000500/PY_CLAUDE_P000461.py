
n=int(input())
a=list(map(int,input().split()))
lo,hi,res=0,n-1,-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==1: res=mid;hi=mid-1
    else: lo=mid+1
print(res)
