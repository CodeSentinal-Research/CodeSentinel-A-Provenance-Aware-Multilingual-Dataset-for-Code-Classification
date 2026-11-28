import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    arr = list(map(int, input_data[2:2+n]))
    
    # Use a min-heap of size k to find the kth largest
    if k == 0:
        print(0)
        return
        
    heap = []
    for num in arr:
        if len(heap) < k:
            heapq.heappush(heap, num)
        elif num > heap[0]:
            heapq.heapreplace(heap, num)
            
    print(heap[0])

if __name__ == "__main__":
    solve()

