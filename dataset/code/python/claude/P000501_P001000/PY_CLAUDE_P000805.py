
n=int(input());a=list(map(int,input().split()))
from collections import defaultdict

cnt=defaultdict(int);cnt[0]=1;s=0;ans=0
for v in a:
    s+=(1 if v>0 else -1 if v<0 else 0)
    ans+=cnt[s];cnt[s]+=1
print(ans)
