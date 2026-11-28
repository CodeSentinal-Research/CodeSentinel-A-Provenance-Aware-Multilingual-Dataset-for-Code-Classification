
from collections import defaultdict
n=int(input());a=list(map(int,input().split()));k=int(input())
cnt=defaultdict(int);cnt[0]=1;odds=0;ans=0
for v in a: odds+=v%2;ans+=cnt[odds-k];cnt[odds]+=1
print(ans)
