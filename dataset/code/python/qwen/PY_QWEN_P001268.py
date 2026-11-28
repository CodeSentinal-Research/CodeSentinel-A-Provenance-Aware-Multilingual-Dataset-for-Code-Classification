import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    
    events = []
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        events.append((start, end))
        
    events.sort()
    
    heap = [] # Min-heap of end times
    count = 0
    
    for start, end in events:
        if heap and heap[0] < start:
            heapq.heappop(heap)
        heapq.heappush(heap, end)
        
    print(len(heap))

if __name__ == "__main__":
    solve()

