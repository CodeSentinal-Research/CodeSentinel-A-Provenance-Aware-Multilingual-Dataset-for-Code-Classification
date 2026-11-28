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

def delete_root(arr: List[int]) -> List[int]:
    if not arr:
        return []
    last = arr.pop()
    if arr:
        arr[0] = last
        max_heapify(arr, len(arr), 0)
    return arr

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    res = delete_root(arr)
    print(" ".join(map(str, res)))