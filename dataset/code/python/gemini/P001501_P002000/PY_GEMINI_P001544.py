from typing import List

def count_windows_sum_gt_x(nums: List[int], k: int, x: int) -> int:
    if len(nums) < k:
        return 0
    cur_sum = sum(nums[:k])
    ans = 1 if cur_sum > x else 0

    for i in range(k, len(nums)):
        cur_sum += nums[i] - nums[i - k]
        if cur_sum > x:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k, x = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_windows_sum_gt_x(nums, k, x))