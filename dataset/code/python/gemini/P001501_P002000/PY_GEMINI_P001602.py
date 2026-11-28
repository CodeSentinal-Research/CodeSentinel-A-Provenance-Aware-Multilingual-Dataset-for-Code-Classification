from typing import List

def max_abs_prefix_sum(nums: List[int]) -> int:
    cur = max_abs = 0
    for x in nums:
        cur += x
        max_abs = max(max_abs, abs(cur))
    return max_abs

if __name__ == '__main__':
    n = int(input())
    nums = list(map(int, input().split()))
    print(max_abs_prefix_sum(nums))