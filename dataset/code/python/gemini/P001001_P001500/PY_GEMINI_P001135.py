from typing import List

def max_sum_non_adjacent(arr: List[int]) -> int:
    inc = 0
    exc = 0
    for x in arr:
        new_inc = exc + x
        new_exc = max(inc, exc)
        inc = new_inc
        exc = new_exc
    return max(inc, exc)

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    print(max_sum_non_adjacent(arr))