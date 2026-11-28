# problem title : Decrease Key in a Min Heap
# Solve the stated task using standard input and standard output.
from typing import List

def decrease_key(arr: List[int], idx: int, new_val: int):
    arr[idx] = new_val
    i = idx
    while i > 0:
        p = (i - 1) // 2
        if arr[i] < arr[p]:
            arr[i], arr[p] = arr[p], arr[i]
            i = p
        else:
            break

if __name__ == '__main__':
    n, idx, new_val = map(int, input().split())
    arr = list(map(int, input().split()))
    decrease_key(arr, idx, new_val)
    print(" ".join(map(str, arr)))
