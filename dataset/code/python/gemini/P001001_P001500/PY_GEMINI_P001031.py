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

def merge_max_heaps(a: List[int], b: List[int]) -> List[int]:
    merged = a + b
    n = len(merged)
    for i in range(n // 2 - 1, -1, -1):
        max_heapify(merged, n, i)
    return merged

if __name__ == '__main__':
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    res = merge_max_heaps(a, b)
    print(" ".join(map(str, res)))