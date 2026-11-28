import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    quality = list(map(int, input_data[idx:idx+n])); idx += n
    wage = list(map(int, input_data[idx:idx+n])); idx += n
    
    workers = sorted(zip(wage, quality), key=lambda x: x[0]/x[1])
    max_heap = []
    quality_sum = 0
    min_cost = float('inf')
    
    for w, q in workers:
        heapq.heappush(max_heap, -q)
        quality_sum += q
        if len(max_heap) > k:
            quality_sum += heapq.heappop(max_heap)
        if len(max_heap) == k:
            ratio = w / q
            min_cost = min(min_cost, quality_sum * ratio)
            
    print(min_cost)

if __name__ == "__main__":
    solve()

