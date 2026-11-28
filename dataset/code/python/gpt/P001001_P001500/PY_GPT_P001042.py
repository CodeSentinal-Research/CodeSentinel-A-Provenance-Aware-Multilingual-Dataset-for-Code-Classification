# problem title : Find All Leaf Nodes of a Heap
# Solve the stated task using standard input and standard output.
from typing import List

def leaf_nodes(arr: List[int]) -> List[int]:
    n = len(arr)
    leaf_start = n // 2
    return arr[leaf_start:]

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(" ".join(map(str, leaf_nodes(arr))))
