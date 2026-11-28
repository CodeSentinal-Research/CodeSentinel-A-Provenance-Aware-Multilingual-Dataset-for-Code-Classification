import sys
from collections import Counter
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    arr = list(map(int, input_data[2:2+n]))
    
    counter = Counter(arr)
    # Min heap of frequencies
    heap = list(counter.values())
    heapq.heapify(heap)
    
    removed = 0
    while heap and removed < k:
        freq = heapq.heappop(heap)
        if k >= freq:
            k -= freq
            removed += 1 # This logic is wrong. We remove elements, not distinct counts directly.
            # Correct: Remove all occurrences of least frequent element
            pass
            
    # Correct approach:
    # Sort by frequency. Remove elements with lowest frequency first.
    freqs = sorted(counter.values())
    distinct = len(freqs)
    for f in freqs:
        if k >= f:
            k -= f
            distinct -= 1
        else:
            break
            
    print(distinct)

if __name__ == "__main__":
    solve()

