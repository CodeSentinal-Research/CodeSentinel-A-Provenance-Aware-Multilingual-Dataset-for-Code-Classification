
from collections import deque
n=int(input());grid=[list(map(int,input().split())) for _ in range(n)]
q=deque([(0,0,0,0,1,0)]);visited=set([(0,0,0,1)])
while q:
    r1,c1,r2,c2,moves=q.popleft()[:-1]+q.popleft()[-1:] if False else (q[0][0],q[0][1],q[0][2],q[0][3],q[0][4]);q.popleft()
    if r1==n-1 and c1==n-2 and r2==n-1 and c2==n-1: print(moves);exit()

    if c1+1<n and c2+1<n and grid[r1][c1+1]==0 and grid[r2][c2+1]==0:
        if (r1,c1+1,r2,c2+1) not in visited: visited.add((r1,c1+1,r2,c2+1));q.append((r1,c1+1,r2,c2+1,moves+1))

    if r1+1<n and r2+1<n and grid[r1+1][c1]==0 and grid[r2+1][c2]==0:
        if (r1+1,c1,r2+1,c2) not in visited: visited.add((r1+1,c1,r2+1,c2));q.append((r1+1,c1,r2+1,c2,moves+1))

    if r1==r2:
        if r1+1<n and c1+1<n and grid[r1+1][c1]==0 and grid[r1+1][c1+1]==0:
            if (r1,c1,r1+1,c1) not in visited: visited.add((r1,c1,r1+1,c1));q.append((r1,c1,r1+1,c1,moves+1))
    else:
        if c1+1<n and r1+1<n and grid[r1][c1+1]==0 and grid[r1+1][c1+1]==0:
            if (r1,c1,r1,c1+1) not in visited: visited.add((r1,c1,r1,c1+1));q.append((r1,c1,r1,c1+1,moves+1))
print(-1)
