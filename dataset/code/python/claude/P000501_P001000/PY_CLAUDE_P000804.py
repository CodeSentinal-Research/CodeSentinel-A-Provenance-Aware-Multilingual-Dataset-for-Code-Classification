
n=int(input());a=list(map(int,input().split()));k=int(input())
from collections import defaultdict
cnt=defaultdict(int);cnt[0]=1;xr=0;ans=0
for v in a: xr^=v;ans+=cnt[xr^k];cnt[xr]+=1
print(ans)
