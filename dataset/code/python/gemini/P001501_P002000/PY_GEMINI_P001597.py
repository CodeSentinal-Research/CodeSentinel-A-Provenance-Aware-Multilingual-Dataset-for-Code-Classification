from typing import List

def count_equal_in_range(nums: List[int], l: int, r: int, x: int) -> int:
    return sum(1 for val in nums[l:r + 1] if val == x)

if __name__ == '__main__':
    n, l, r, x = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_equal_in_range(nums, l, r, x))