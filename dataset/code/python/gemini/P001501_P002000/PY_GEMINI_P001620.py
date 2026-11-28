from typing import List

def sum_alternate_in_range(nums: List[int], l: int, r: int) -> int:
    return sum(nums[i] for i in range(l, r + 1, 2))

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    nums = list(map(int, input().split()))
    print(sum_alternate_in_range(nums, l, r))