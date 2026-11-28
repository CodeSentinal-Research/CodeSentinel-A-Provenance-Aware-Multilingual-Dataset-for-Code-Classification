
n=int(input())
a=list(map(int,input().split()))
lo,hi,res=0,n-1,-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==mid: res=mid;hi=mid-1
    elif a[mid]<mid: lo=mid+1
    else: hi=mid-1
print(res)
