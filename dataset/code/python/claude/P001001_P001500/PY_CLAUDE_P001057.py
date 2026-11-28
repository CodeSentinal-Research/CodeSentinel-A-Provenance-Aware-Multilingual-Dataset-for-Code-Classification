
from collections import Counter
n,k=map(int,input().split());a=list(map(int,input().split()))
cnt=Counter(a)
res=sum(1 for v in cnt.values() if v<=k)
for v in sorted(cnt.values(),reverse=True):
    if v>k and k>0: k-=v-1;res+=1
print(res)
