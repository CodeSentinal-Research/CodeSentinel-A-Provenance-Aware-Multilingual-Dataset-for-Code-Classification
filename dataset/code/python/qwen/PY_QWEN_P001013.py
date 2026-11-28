import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    max_heap = [] # stores negative values
    min_heap = []
    
    results = []
    
    for num in arr:
        if not max_heap or num <= -max_heap[0]:
            heapq.heappush(max_heap, -num)
        else:
            heapq.heappush(min_heap, num)
            
        # Balance heaps
        if len(max_heap) > len(min_heap) + 1:
            heapq.heappush(min_heap, -heapq.heappop(max_heap))
        elif len(min_heap) > len(max_heap):
            heapq.heappush(max_heap, -heapq.heappop(min_heap))
            
        if len(max_heap) > len(min_heap):
            median = -max_heap[0]
        else:
            median = (-max_heap[0] + min_heap[0]) / 2
            if median == int(median):
                median = int(median)
                
        results.append(str(median))
        
    print(" ".join(results))

if __name__ == "__main__":
    solve()

