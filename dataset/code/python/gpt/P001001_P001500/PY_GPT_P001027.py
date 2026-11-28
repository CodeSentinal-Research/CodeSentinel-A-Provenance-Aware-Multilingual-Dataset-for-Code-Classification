# problem title : Print Heap Level Order
# Solve the stated task using standard input and standard output.
from typing import List

def print_levels(arr: List[int]):
    n = len(arr)
    level = 0
    start = 0
    while start < n:
        count = 1 << level
        end = min(n, start + count)
        print(" ".join(map(str, arr[start:end])))
        start = end
        level += 1

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print_levels(arr)
