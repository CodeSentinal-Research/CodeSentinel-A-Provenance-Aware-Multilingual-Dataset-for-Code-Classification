import sys
from collections import deque
def solve():
    input_data = sys.stdin.read().split()
    if not input_data: return
    r = int(input_data[0])
    routes = []
    idx = 1
    for _ in range(r):
        sz = int(input_data[idx]); idx += 1
        routes.append(set(map(int, input_data[idx:idx+sz])))
        idx += sz
    src = int(input_data[idx]); tgt = int(input_data[idx+1])
    if src == tgt:
        print(0)
        return
    q = deque()
    vis_buses = set()
    vis_stops = {src}
    for i, route in enumerate(routes):
        if src in route:
            q.append((i, 1))
            vis_buses.add(i)
    while q:
        bus, cnt = q.popleft()
        for stop in routes[bus]:
            if stop == tgt:
                print(cnt)
                return
            if stop not in vis_stops:
                vis_stops.add(stop)
                for i, route in enumerate(routes):
                    if i not in vis_buses and stop in route:
                        vis_buses.add(i)
                        q.append((i, cnt + 1))
    print(-1)
solve()
