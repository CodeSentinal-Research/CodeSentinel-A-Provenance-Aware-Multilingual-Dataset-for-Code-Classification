
from collections import defaultdict
n=int(input());a=list(map(int,input().split()));goal=int(input())
cnt=defaultdict(int);cnt[0]=1;s=0;ans=0
for v in a: s+=v;ans+=cnt[s-goal];cnt[s]+=1
print(ans)
