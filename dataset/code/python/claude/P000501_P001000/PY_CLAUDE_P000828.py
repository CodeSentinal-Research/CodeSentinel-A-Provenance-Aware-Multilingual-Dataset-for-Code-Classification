
n=int(input());ivs=[list(map(int,input().split())) for _ in range(n)]
from bisect import bisect_left
starts=sorted((iv[0],i) for i,iv in enumerate(ivs))
res=[]
for i,iv in enumerate(ivs):
    target=iv[1]
    pos=bisect_left(starts,(target,))
    if pos<n and starts[pos][0]>=target: res.append(starts[pos][1])
    else: res.append(-1)
print(*res)
