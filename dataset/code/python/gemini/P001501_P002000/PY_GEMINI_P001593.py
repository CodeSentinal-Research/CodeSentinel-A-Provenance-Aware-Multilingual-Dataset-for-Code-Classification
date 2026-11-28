from typing import List

def shortest_prefix_gt_x(nums: List[int], x: int) -> int:
    cur_sum = 0
    for i, val in enumerate(nums):
        cur_sum += val
        if cur_sum > x:
            return i + 1
    return -1

if __name__ == '__main__':
    n, x = map(int, input().split())
    nums = list(map(int, input().split()))
    print(shortest_prefix_gt_x(nums, x))