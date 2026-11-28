
import heapq
n=int(input());heights=list(map(int,input().split()));ladders=int(input());bricks=int(input())
h=[]
for i in range(n-1):
    d=heights[i+1]-heights[i]
    if d>0:
        heapq.heappush(h,d)
        if len(h)>ladders:
            bricks-=heapq.heappop(h)
            if bricks<0: print(i);exit()
print(n-1)
