
n=int(input());a=list(map(int,input().split()));k=int(input())
lo,hi=1,a[-1]+k
while lo<hi:
    mid=(lo+hi)//2
    missing=mid-sum(1 for v in a if v<=mid)
    if missing<k: lo=mid+1
    else: hi=mid
print(lo)
