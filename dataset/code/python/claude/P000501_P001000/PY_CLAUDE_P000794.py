
n=int(input());a=list(map(int,input().split()));k=int(input())

from collections import defaultdict
pre={0:-1};s=0;best=0
for i,v in enumerate(a):
    s+=v
    if s-k in pre:
        best=max(best,i-pre[s-k])
    pre.setdefault(s,i)
print(best)
