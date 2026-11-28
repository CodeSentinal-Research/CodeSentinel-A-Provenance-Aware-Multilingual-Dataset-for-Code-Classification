# problem title : Heapify a Subtree
# Solve the stated task using standard input and standard output.
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

if __name__ == '__main__':
    n, idx = map(int, input().split())
    arr = list(map(int, input().split()))
    max_heapify(arr, n, idx)
    print(" ".join(map(str, arr)))
