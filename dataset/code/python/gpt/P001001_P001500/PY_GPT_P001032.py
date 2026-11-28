# problem title : Replace Root in a Min Heap
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

def replace_root_min(arr: List[int], x: int):
    arr[0] = x
    min_heapify(arr, len(arr), 0)

if __name__ == '__main__':
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    replace_root_min(arr, x)
    print(" ".join(map(str, arr)))
