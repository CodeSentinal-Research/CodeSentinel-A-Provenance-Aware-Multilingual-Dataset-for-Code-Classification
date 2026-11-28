
n=int(input());a=list(map(int,input().split()));thresh=int(input())
def ok(d):
    return sum((v+d-1)//d for v in a)<=thresh
lo,hi=1,max(a)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
