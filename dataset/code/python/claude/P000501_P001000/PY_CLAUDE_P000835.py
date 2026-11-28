
n=int(input());stalls=sorted(map(int,input().split()));k=int(input())
def ok(dist):
    cnt=1;last=stalls[0]
    for s in stalls[1:]:
        if s-last>=dist: cnt+=1;last=s
    return cnt>=k
lo,hi=1,stalls[-1]-stalls[0]
while lo<hi:
    mid=(lo+hi+1)//2
    if ok(mid): lo=mid
    else: hi=mid-1
print(lo)
