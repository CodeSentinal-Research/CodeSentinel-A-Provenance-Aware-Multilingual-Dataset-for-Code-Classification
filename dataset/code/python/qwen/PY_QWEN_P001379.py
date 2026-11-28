import sys
from collections import Counter
import heapq

def solve():
    input_data = sys.stdin.read().split()
    if not input_data:
        return
    n = int(input_data[0])
    k = int(input_data[1])
    nums = list(map(int, input_data[2:2+n]))
    
    counter = Counter(nums)
    # Sort by frequency desc, then value asc
    items = sorted(counter.items(), key=lambda x: (-x[1], x[0]))
    
    result = [str(x[0]) for x in items[:k]]
    print(" ".join(result))

solve()

