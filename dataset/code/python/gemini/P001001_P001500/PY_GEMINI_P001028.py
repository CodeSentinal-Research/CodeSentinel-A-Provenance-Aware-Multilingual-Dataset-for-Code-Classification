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

def delete_index(arr: List[int], idx: int) -> List[int]:
    n = len(arr)
    arr[idx] = arr[-1]
    arr.pop()
    if idx < len(arr):
        # heapify up or down
        p = (idx - 1) // 2
        if idx > 0 and arr[idx] > arr[p]:
            while idx > 0 and arr[idx] > arr[(idx - 1) // 2]:
                arr[idx], arr[(idx - 1) // 2] = arr[(idx - 1) // 2], arr[idx]
                idx = (idx - 1) // 2
        else:
            max_heapify(arr, len(arr), idx)
    return arr

if __name__ == '__main__':
    n, idx = map(int, input().split())
    arr = list(map(int, input().split()))
    res = delete_index(arr, idx)
    print(" ".join(map(str, res)))