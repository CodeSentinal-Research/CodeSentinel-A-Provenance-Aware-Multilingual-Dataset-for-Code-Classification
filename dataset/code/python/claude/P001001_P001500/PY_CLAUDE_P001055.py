
import heapq
dest=int(input());fuel=int(input());m=int(input())
stations=[]
for _ in range(m):
    pos,cap=map(int,input().split())
    stations.append((pos,cap))
stations.sort()
stops=0;curr_fuel=fuel;h=[];i=0;curr_pos=0
for target_pos,_ in stations+[(dest,0)]:
    curr_fuel-=target_pos-curr_pos;curr_pos=target_pos
    while curr_fuel<0 and h:
        curr_fuel+=-heapq.heappop(h);stops+=1
    if curr_fuel<0: print(-1);exit()
    if _: heapq.heappush(h,-_)
print(stops)
