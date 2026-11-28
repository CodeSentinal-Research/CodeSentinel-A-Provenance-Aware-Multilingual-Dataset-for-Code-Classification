from typing import List

def max_heapify(arr: List[int], n: int, i: int):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]: largest = l
    if r < n and arr[r] > arr[largest]: largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        max_heapify(arr, n, largest)

def rebuild_heap(arr: List[int]):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    for _ in range(k):
        idx, val = map(int, input().split())
        arr[idx] = val
    rebuild_heap(arr)
    print(" ".join(map(str, arr)))