
from collections import OrderedDict,Counter
n=int(input());a=list(map(int,input().split()));q=int(input())
cnt=Counter();order=OrderedDict()
for v in a:
    cnt[v]+=1
    if cnt[v]==1: order[v]=True
    elif v in order: del order[v]
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='add':
        v=int(cmd[1]);cnt[v]+=1
        if cnt[v]==1: order[v]=True
        elif v in order: del order[v]
    else: print(next(iter(order)) if order else -1)
