# problem title : Merge Two Min Heaps
# Solve the stated task using standard input and standard output.
from typing import List

def min_heapify(arr: List[int], n: int, i: int):
    smallest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] < arr[smallest]: smallest = l
    if r < n and arr[r] < arr[smallest]: smallest = r
    if smallest != i:
        arr[i], arr[smallest] = arr[smallest], arr[i]
        min_heapify(arr, n, smallest)

def merge_min_heaps(a: List[int], b: List[int]) -> List[int]:
    merged = a + b
    n = len(merged)
    for i in range(n // 2 - 1, -1, -1):
        min_heapify(merged, n, i)
    return merged

if __name__ == '__main__':
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = merge_min_heaps(a, b)
    print(" ".join(map(str, res)))
