
from collections import deque
x,y=map(int,input().split());x,y=abs(x),abs(y)
q=deque([(0,0,0)]);vis={(0,0)}
while q:
    cx,cy,d=q.popleft()
    if cx==x and cy==y: print(d);exit()
    for dx,dy in [(2,1),(2,-1),(-2,1),(-2,-1),(1,2),(1,-2),(-1,2),(-1,-2)]:
        nx,ny=cx+dx,cy+dy
        if (nx,ny) not in vis and -2<=nx<=x+2 and -2<=ny<=y+2:
            vis.add((nx,ny));q.append((nx,ny,d+1))
