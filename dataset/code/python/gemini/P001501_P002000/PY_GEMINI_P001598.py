from typing import List

def count_evens_in_range(nums: List[int], l: int, r: int) -> int:
    return sum(1 for x in nums[l:r + 1] if x % 2 == 0)

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_evens_in_range(nums, l, r))