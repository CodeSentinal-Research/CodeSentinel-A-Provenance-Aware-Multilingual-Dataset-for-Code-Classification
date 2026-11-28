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

def min_to_max_heap(arr: List[int]):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(arr, n, i)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    min_to_max_heap(arr)
    print(" ".join(map(str, arr)))