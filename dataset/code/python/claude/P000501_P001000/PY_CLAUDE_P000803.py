
n,m=map(int,input().split());t=int(input())
grid=[list(map(int,input().split())) for _ in range(n)]
from collections import defaultdict
ans=0
for r1 in range(n):
    col=[0]*m
    for r2 in range(r1,n):
        for c in range(m): col[c]+=grid[r2][c]
        cnt=defaultdict(int);cnt[0]=1;s=0
        for v in col: s+=v;ans+=cnt[s-t];cnt[s]+=1
print(ans)
