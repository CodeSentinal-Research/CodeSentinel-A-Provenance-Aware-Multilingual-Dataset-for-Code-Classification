
n,c=map(int,input().split())
stalls=sorted(map(int,input().split()))
def ok(d):
    count=1;last=stalls[0]
    for s in stalls[1:]:
        if s-last>=d: count+=1;last=s
    return count>=c
lo,hi=1,stalls[-1]-stalls[0];ans=0
while lo<=hi:
    mid=(lo+hi)//2
    if ok(mid): ans=mid;lo=mid+1
    else: hi=mid-1
print(ans)
