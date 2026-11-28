from typing import List

def sum_between_positions(nums: List[int], l: int, r: int) -> int:
    return sum(nums[l:r + 1])

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    print(sum_between_positions(nums, l, r))