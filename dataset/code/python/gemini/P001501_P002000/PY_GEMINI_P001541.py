from typing import List

def max_sum_k_consecutive(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    cur_sum = sum(nums[:k])
    max_sum = cur_sum

    for i in range(k, len(nums)):
        cur_sum += nums[i] - nums[i - k]
        max_sum = max(max_sum, cur_sum)

    return max_sum

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(max_sum_k_consecutive(nums, k))