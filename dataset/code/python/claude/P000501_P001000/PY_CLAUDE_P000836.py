
n=int(input());pos=sorted(map(int,input().split()));m=int(input())
def ok(d):
    cnt=1;last=pos[0]
    for p in pos[1:]:
        if p-last>=d: cnt+=1;last=p
    return cnt>=m
lo,hi=1,pos[-1]-pos[0]
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
