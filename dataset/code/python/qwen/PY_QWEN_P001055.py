import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    target = int(input_data[idx]); idx += 1
    start_fuel = int(input_data[idx]); idx += 1
    n = int(input_data[idx]); idx += 1
    
    stations = []
    for _ in range(n):
        pos = int(input_data[idx]); idx += 1
        fuel = int(input_data[idx]); idx += 1
        stations.append((pos, fuel))
        
    stations.sort()
    
    max_heap = []
    stops = 0
    curr_fuel = start_fuel
    prev_pos = 0
    
    for pos, fuel in stations:
        dist = pos - prev_pos
        curr_fuel -= dist
        while curr_fuel < 0 and max_heap:
            curr_fuel += -heapq.heappop(max_heap)
            stops += 1
        if curr_fuel < 0:
            print(-1)
            return
        heapq.heappush(max_heap, -fuel)
        prev_pos = pos
        
    # Final stretch
    dist = target - prev_pos
    curr_fuel -= dist
    while curr_fuel < 0 and max_heap:
        curr_fuel += -heapq.heappop(max_heap)
        stops += 1
    if curr_fuel < 0:
        print(-1)
    else:
        print(stops)

if __name__ == "__main__":
    solve()

