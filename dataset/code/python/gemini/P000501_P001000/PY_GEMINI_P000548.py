import sys
from collections import defaultdict, deque
def main():
    tokens = sys.stdin.read().split()
    if tokens:
        r = int(tokens[0])
        idx = 1
        routes = []
        stop_to_routes = defaultdict(list)
        for bus in range(r):
            k = int(tokens[idx])
            route = list(map(int, tokens[idx+1:idx+1+k]))
            routes.append(route)
            for stop in route:
                stop_to_routes[stop].append(bus)
            idx += 1 + k
        source = int(tokens[idx])
        target = int(tokens[idx+1])
        if source == target:
            print(0)
            return
        q = deque([(source, 0)])
        visited_stops = {source}
        visited_routes = set()
        while q:
            stop, buses = q.popleft()
            for bus in stop_to_routes[stop]:
                if bus not in visited_routes:
                    visited_routes.add(bus)
                    for nxt_stop in routes[bus]:
                        if nxt_stop == target:
                            print(buses + 1)
                            return
                        if nxt_stop not in visited_stops:
                            visited_stops.add(nxt_stop)
                            q.append((nxt_stop, buses + 1))
        print(-1)
if __name__ == '__main__':
    main()