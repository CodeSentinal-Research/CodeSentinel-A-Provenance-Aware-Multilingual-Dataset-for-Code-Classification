# problem title : Find K Smallest Elements
# Solve the stated task using standard input and standard output.
from typing import List
import heapq

def k_smallest_elements(arr: List[int], k: int) -> List[int]:
    return sorted(heapq.nsmallest(k, arr))

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    print(" ".join(map(str, k_smallest_elements(arr, k))))
