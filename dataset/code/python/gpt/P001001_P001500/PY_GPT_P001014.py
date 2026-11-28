# problem title : Merge K Sorted Arrays
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def merge_k_sorted_arrays(arrays: List[List[int]]) -> List[int]:
    heap = []
    for i, arr in enumerate(arrays):
        if arr:
            heapq.heappush(heap, (arr[0], i, 0))
    res = []
    while heap:
        val, r, c = heapq.heappop(heap)
        res.append(val)
        if c + 1 < len(arrays[r]):
            heapq.heappush(heap, (arrays[r][c + 1], r, c + 1))
    return res

if __name__ == '__main__':
    k = int(input())
    arrays = []
    for _ in range(k):
        arrays.append(list(map(int, input().split())))
    print(" ".join(map(str, merge_k_sorted_arrays(arrays))))
