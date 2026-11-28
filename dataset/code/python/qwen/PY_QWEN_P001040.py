import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    speeds = list(map(int, input_data[idx:idx+n])); idx += n
    efficiencies = list(map(int, input_data[idx:idx+n])); idx += n
    
    engineers = sorted(zip(efficiencies, speeds), reverse=True)
    min_heap = []
    speed_sum = 0
    max_perf = 0
    
    for eff, spd in engineers:
        heapq.heappush(min_heap, spd)
        speed_sum += spd
        if len(min_heap) > k:
            speed_sum -= heapq.heappop(min_heap)
        max_perf = max(max_perf, speed_sum * eff)
        
    print(max_perf % (10**9 + 7))

if __name__ == "__main__":
    solve()

