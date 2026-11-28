# problem title : Find the Minimum Element in a Heap
# Solve the stated task using standard input and standard output.
from typing import List

def find_min_in_max_heap(arr: List[int]) -> int:
    n = len(arr)
    leaf_start = n // 2
    return min(arr[leaf_start:])

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(find_min_in_max_heap(arr))
