import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    arr = list(map(int, input_data[2:2+n]))
    
    # Max heap of size k for k smallest
    heap = []
    for num in arr:
        if len(heap) < k:
            heapq.heappush(heap, -num)
        elif -num > heap[0]:
            heapq.heapreplace(heap, -num)
            
    result = [-x for x in heap]
    print(*result)

if __name__ == "__main__":
    solve()

