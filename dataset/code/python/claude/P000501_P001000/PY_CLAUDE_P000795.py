
from collections import defaultdict
n=int(input());a=list(map(int,input().split()));k=int(input())
cnt=defaultdict(int);cnt[0]=1;s=0;ans=0
for v in a: s=(s+v)%k;ans+=cnt[s];cnt[s]+=1
print(ans)
