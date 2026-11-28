import sys
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    arr = list(map(int, input_data[1:1+n]))
    
    # Max heap for even numbers (negated)
    max_heap = []
    min_val = float('inf')
    
    for x in arr:
        if x % 2 == 0:
            heapq.heappush(max_heap, -x)
        min_val = min(min_val, x)
        
    # To minimize deviation, we can only decrease evens (by half) or increase odds (by double, once).
    # Strategy: Double all odds first. Then repeatedly halve the max even.
    
    for i in range(n):
        if arr[i] % 2 != 0:
            arr[i] *= 2
        heapq.heappush(max_heap, -arr[i]) # Re-push all
        
    min_val = min(arr)
    min_dev = max(arr) - min_val
    
    while max_heap:
        max_val = -heapq.heappop(max_heap)
        min_dev = min(min_dev, max_val - min_val)
        if max_val % 2 != 0:
            break
        new_val = max_val // 2
        min_val = min(min_val, new_val)
        heapq.heappush(max_heap, -new_val)
        
    print(min_dev)

if __name__ == "__main__":
    solve()

