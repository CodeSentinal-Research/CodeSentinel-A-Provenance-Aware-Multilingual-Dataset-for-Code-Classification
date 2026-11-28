
n=int(input());price=list(map(int,input().split()));k=int(input())
price.sort()
def ok(taste):
    cnt=1;last=price[0]
    for p in price[1:]:
        if p-last>=taste: cnt+=1;last=p
    return cnt>=k
lo,hi=0,price[-1]-price[0]
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
