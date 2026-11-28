from typing import List

def min_sum_window(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_sum = sum(nums[:k])
    min_sum = cur_sum

    for i in range(k, len(nums)):
        cur_sum += nums[i] - nums[i - k]
        min_sum = min(min_sum, cur_sum)

    return min_sum

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(min_sum_window(nums, k))