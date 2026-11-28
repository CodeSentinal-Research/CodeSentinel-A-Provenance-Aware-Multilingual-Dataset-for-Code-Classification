
n=int(input());a=list(map(int,input().split()));t=int(input())
lo,hi=0,n-1;res=-1
while lo<=hi:
    mid=(lo+hi)//2
    if a[mid]==t: res=mid;lo=mid+1
    elif a[mid]<t: lo=mid+1
    else: hi=mid-1
print(res)
