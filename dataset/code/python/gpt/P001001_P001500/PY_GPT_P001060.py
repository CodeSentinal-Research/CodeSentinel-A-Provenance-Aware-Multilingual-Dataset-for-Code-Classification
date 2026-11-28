# problem title : Sort Nearly Sorted Array
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def sort_nearly_sorted(arr: List[int], k: int) -> List[int]:
    heap = arr[:k + 1]
    heapq.heapify(heap)
    res = []
    for i in range(k + 1, len(arr)):
        res.append(heapq.heappop(heap))
        heapq.heappush(heap, arr[i])
    while heap:
        res.append(heapq.heappop(heap))
    return res

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(" ".join(map(str, sort_nearly_sorted(arr, k))))
