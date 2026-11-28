import sys
from collections import Counter
import heapq

def solve():
    s = sys.stdin.readline().strip()
    counter = Counter(s)
    max_heap = [(-freq, char) for char, freq in counter.items()]
    heapq.heapify(max_heap)
    
    result = []
    prev_freq, prev_char = 0, ''
    
    while max_heap:
        freq, char = heapq.heappop(max_heap)
        result.append(char)
        freq += 1 # because freq is negative
        
        if prev_freq < 0:
            heapq.heappush(max_heap, (prev_freq, prev_char))
            
        prev_freq, prev_char = freq, char
        
    if len(result) == len(s):
        print("".join(result))
    else:
        print("IMPOSSIBLE")

if __name__ == "__main__":
    solve()

