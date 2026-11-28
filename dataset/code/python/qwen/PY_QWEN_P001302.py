import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    meetings = []
    idx = 1
    for _ in range(n):
        start = int(input_data[idx]); idx += 1
        end = int(input_data[idx]); idx += 1
        meetings.append((start, end))
        
    meetings.sort()
    
    # Min-heap of end times
    heap = []
    for start, end in meetings:
        if heap and heap[0] <= start:
            heapq.heappop(heap)
        heapq.heappush(heap, end)
        
    print(len(heap))

if __name__ == "__main__":
    solve()

