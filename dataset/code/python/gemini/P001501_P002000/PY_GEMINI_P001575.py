from typing import List

def min_first_window(nums: List[int], k: int) -> int:
    return min(nums[:k])

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(min_first_window(nums, k))