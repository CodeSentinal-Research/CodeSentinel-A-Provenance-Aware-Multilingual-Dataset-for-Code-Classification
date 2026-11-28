from typing import List

def smallest_prefix_at_least_x(nums: List[int], x: int) -> int:
    cur = 0
    for i, val in enumerate(nums):
        cur += val
        if cur >= x:
            return i + 1
    return -1

if __name__ == '__main__':
    n, x = map(int, input().split())
    nums = list(map(int, input().split()))
    print(smallest_prefix_at_least_x(nums, x))