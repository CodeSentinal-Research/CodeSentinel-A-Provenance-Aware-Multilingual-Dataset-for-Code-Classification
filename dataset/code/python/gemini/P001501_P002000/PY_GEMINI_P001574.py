from typing import List

def max_first_window(nums: List[int], k: int) -> int:
    return max(nums[:k])

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_first_window(nums, k))