from typing import List

def count_multiples_in_range(nums: List[int], l: int, r: int, k: int) -> int:
    return sum(1 for x in nums[l:r + 1] if x % k == 0)

if __name__ == '__main__':
    n, l, r, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_multiples_in_range(nums, l, r, k))