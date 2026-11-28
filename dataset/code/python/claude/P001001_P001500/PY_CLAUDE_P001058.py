
from collections import defaultdict
import heapq
q=int(input())
freq=defaultdict(int)
group=defaultdict(list)
max_freq=0;counter=0
for _ in range(q):
    parts=input().split()
    if parts[0]=='push':
        v=int(parts[1]);freq[v]+=1;f=freq[v]
        max_freq=max(max_freq,f)
        group[f].append((counter,v));counter+=1;print('ok')
    else:
        while not group[max_freq]: max_freq-=1
        _,v=group[max_freq].pop()
        freq[v]-=1;print(v)
