import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    idx = 0
    n = int(input_data[idx]); idx += 1
    k = int(input_data[idx]); idx += 1
    
    points = []
    for i in range(n):
        x = int(input_data[idx]); idx += 1
        y = int(input_data[idx]); idx += 1
        dist_sq = x*x + y*y
        points.append((dist_sq, x, y))
        
    # Max heap of size k
    heap = []
    for dist_sq, x, y in points:
        if len(heap) < k:
            heapq.heappush(heap, (-dist_sq, x, y))
        elif -dist_sq > heap[0][0]:
            heapq.heapreplace(heap, (-dist_sq, x, y))
            
    result = [(x, y) for _, x, y in heap]
    for x, y in result:
        print(x, y)

if __name__ == "__main__":
    solve()

