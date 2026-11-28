from typing import List

def sum_heap_elements(arr: List[int]) -> int:
    return sum(arr)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(sum_heap_elements(arr))