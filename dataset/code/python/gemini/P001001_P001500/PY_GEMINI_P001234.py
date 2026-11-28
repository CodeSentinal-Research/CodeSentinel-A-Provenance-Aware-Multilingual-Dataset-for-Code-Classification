from typing import List

def min_platforms(arr: List[int], dep: List[int]) -> int:
    arr.sort()
    dep.sort()
    n = len(arr)
    i, j = 0, 0
    plat_needed = 0
    max_plat = 0

    while i < n and j < n:
        if arr[i] <= dep[j]:
            plat_needed += 1
            max_plat = max(max_plat, plat_needed)
            i += 1
        else:
            plat_needed -= 1
            j += 1

    return max_plat

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    dep = list(map(int, input().split()))
    print(min_platforms(arr, dep))