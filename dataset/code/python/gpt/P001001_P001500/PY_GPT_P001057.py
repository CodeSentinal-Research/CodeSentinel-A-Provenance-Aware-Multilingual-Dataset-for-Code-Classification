# problem title : Maximum Distinct Elements After K Removals
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter
import heapq

def max_distinct_elements(arr: List[int], k: int) -> int:
    count = Counter(arr)
    # Put duplicate counts (>1) in a min-heap
    heap = [c - 1 for c in count.values() if c > 1]
    heapq.heapify(heap)

    while heap and k > 0:
        c = heapq.heappop(heap)
        if k >= c:
            k -= c
        else:
            c -= k
            k = 0
            heapq.heappush(heap, c)

    distinct = len(count)
    if k > 0:
        distinct -= k
    return max(0, distinct)

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(max_distinct_elements(arr, k))
