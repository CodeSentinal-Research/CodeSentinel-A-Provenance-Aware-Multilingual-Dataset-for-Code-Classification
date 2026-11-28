
n=int(input());a=list(map(int,input().split()));ops=int(input())
def ok(mid):
    return sum((v-1)//mid for v in a)<=ops
lo,hi=1,max(a)
while lo<hi:
    mid=(lo+hi)//2
    if ok(mid): hi=mid
    else: lo=mid+1
print(lo)
