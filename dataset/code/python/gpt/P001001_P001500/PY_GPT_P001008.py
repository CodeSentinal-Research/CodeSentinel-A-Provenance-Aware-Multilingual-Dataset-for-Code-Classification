# problem title : Insert an Element into a Min Heap
# Solve the stated task using standard input and standard output.
from typing import List

def insert_min_heap(arr: List[int], val: int) -> List[int]:
    arr.append(val)
    i = len(arr) - 1
    while i > 0:
        p = (i - 1) // 2
        if arr[i] < arr[p]:
            arr[i], arr[p] = arr[p], arr[i]
            i = p
        else:
            break
    return arr

if __name__ == '__main__':
    n, val = map(int, input().split())
    arr = list(map(int, input().split())) if n > 0 else []
    res = insert_min_heap(arr, val)
    print(" ".join(map(str, res)))
