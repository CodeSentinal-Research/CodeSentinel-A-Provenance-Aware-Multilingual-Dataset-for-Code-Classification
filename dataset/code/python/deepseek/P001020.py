import heapq
from typing import List

def smallest_range_covering_k_lists(lists: List[List[int]], k: int) -> List[int]:
    min_heap, max_heap, res = [], [], [float('inf'), float('inf')]
    for l in lists:
        heapq.heappush(min_heap, l[0])
        if len(l) > 1:
            max_heap.append((l[1], l))
            heapq.heapify(max_heap)
    range_min, range_max = min_heap, min_heap
    while len(max_heap) > 0:
        cur_max = -heapq.heappop(max_heap)[0]
        range_min, range_max = min(range_min, min_heap), max(range_max, cur_max)
        min_heap, max_heap = min_heap[1:], max_heap[1:]
        if len(min_heap) > 0:
            heapq.heappush(max_heap, (-min_heap[0], min_heap))
    return [range_min, range_max]