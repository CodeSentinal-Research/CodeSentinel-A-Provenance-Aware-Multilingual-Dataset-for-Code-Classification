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

def build_min_heap(arr: List[int]):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        min_heapify(arr, n, i)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    build_min_heap(arr)
    print(" ".join(map(str, arr)))