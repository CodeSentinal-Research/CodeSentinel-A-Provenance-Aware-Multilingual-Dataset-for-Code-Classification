
from collections import deque
r=int(input());routes=[list(map(int,input().split())) for _ in range(r)];src=int(input());tgt=int(input())
if src==tgt: print(0);exit()
stop_to_routes={}
for i,route in enumerate(routes):
    for stop in route: stop_to_routes.setdefault(stop,[]).append(i)
visited_stops=set([src]);visited_routes=set();q=deque([(src,0)])
while q:
    stop,buses=q.popleft()
    for ri in stop_to_routes.get(stop,[]):
        if ri in visited_routes: continue
        visited_routes.add(ri)
        for ns in routes[ri]:
            if ns==tgt: print(buses+1);exit()
            if ns not in visited_stops: visited_stops.add(ns);q.append((ns,buses+1))
print(-1)
