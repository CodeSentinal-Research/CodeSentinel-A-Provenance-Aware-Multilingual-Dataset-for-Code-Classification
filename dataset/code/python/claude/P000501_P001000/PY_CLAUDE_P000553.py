
from collections import deque
n=int(input());board=[list(map(int,input().split())) for _ in range(n)]
def cell(s):
    s-=1;r=s//n;c=s%n
    if r%2==1: c=n-1-c
    return board[n-1-r][c]
vis={1};q=deque([(1,0)])
while q:
    pos,moves=q.popleft()
    for d in range(1,7):
        nxt=pos+d
        if nxt>n*n: break
        v=cell(nxt)
        if v!=-1: nxt=v
        if nxt==n*n: print(moves+1);exit()
        if nxt not in vis: vis.add(nxt);q.append((nxt,moves+1))
print(-1)
