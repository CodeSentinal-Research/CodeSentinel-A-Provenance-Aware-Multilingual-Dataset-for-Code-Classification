from typing import List

def rotate_right(arr: List[int], k: int) -> List[int]:
    if not arr:
        return []
    k = k % len(arr)
    return arr[-k:] + arr[:-k] if k > 0 else arr[:]

if __name__ == '__main__':
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    res = rotate_right(arr, k)
    print(" ".join(map(str, res)))