import sys
from collections import Counter
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    barcodes = list(map(int, input_data[1:1+n]))
    
    counter = Counter(barcodes)
    max_heap = [(-freq, val) for val, freq in counter.items()]
    heapq.heapify(max_heap)
    
    result = []
    prev_freq, prev_val = 0, 0
    
    while max_heap:
        freq, val = heapq.heappop(max_heap)
        result.append(val)
        freq += 1
        
        if prev_freq < 0:
            heapq.heappush(max_heap, (prev_freq, prev_val))
            
        prev_freq, prev_val = freq, val
        
    print(*result)

if __name__ == "__main__":
    solve()

