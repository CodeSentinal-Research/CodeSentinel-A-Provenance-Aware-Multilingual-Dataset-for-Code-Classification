from typing import List

def smallest_subarray_sum_gt_x(nums: List[int], x: int) -> int:
    l = 0
    cur_sum = 0
    min_len = float('inf')

    for r, val in enumerate(nums):
        cur_sum += val
        while cur_sum > x:
            min_len = min(min_len, r - l + 1)
            cur_sum -= nums[l]
            l += 1

    return min_len if min_len != float('inf') else 0

if __name__ == '__main__':
    n, x = map(int, input().split())
    nums = list(map(int, input().split()))
    print(smallest_subarray_sum_gt_x(nums, x))