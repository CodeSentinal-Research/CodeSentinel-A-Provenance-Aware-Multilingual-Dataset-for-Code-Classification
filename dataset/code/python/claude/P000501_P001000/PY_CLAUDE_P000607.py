
from collections import defaultdict,OrderedDict
q=int(input());cap=int(input())
if cap==0:
    for _ in range(q):
        cmd=input().split()
        if cmd[0]=='get': print(-1)
    exit()
keys={}; freq={}; freq_map=defaultdict(OrderedDict); min_freq=0
def get_(k):
    if k not in keys: print(-1);return
    print(keys[k])
    f=freq[k]; freq_map[f].pop(k)
    if not freq_map[f] and f==min_freq: freq_map.pop(f); globals()['min_freq']+=1 if f+1 in freq_map else 0
    freq[k]=f+1; freq_map[f+1][k]=True
def put_(k,v):
    global min_freq
    if k in keys:
        keys[k]=v
        get_tmp=True
    else:
        if len(keys)==cap:
            evict_k,_=freq_map[min_freq].popitem(last=False)
            if not freq_map[min_freq]: del freq_map[min_freq]
            del keys[evict_k]; del freq[evict_k]
        keys[k]=v; freq[k]=0; freq_map[0][k]=True; min_freq=0; get_tmp=False
    if get_tmp:
        f=freq[k]; freq_map[f].pop(k)
        if not freq_map[f]:
            del freq_map[f]
            if f==min_freq: min_freq=f+1
        freq[k]=f+1; freq_map[f+1][k]=True
for _ in range(q):
    cmd=input().split()
    if cmd[0]=='get': get_(int(cmd[1]))
    else: put_(int(cmd[1]),int(cmd[2]))
