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

def replace_root(arr: List[int], x: int):
    arr[0] = x
    max_heapify(arr, len(arr), 0)

if __name__ == '__main__':
    n, x = map(int, input().split())
    arr = list(map(int, input().split()))
    replace_root(arr, x)
    print(" ".join(map(str, arr)))