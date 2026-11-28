
from collections import defaultdict
n=int(input());a=list(map(int,input().split()))

cnt=defaultdict(int);cnt[0]=1;s=0;ans=0
for v in a: s+=(1 if v==1 else -1);ans+=cnt[s];cnt[s]+=1
print(ans)
