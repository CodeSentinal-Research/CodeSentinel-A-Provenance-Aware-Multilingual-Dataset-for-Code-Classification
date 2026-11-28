from typing import List

def longest_subarray_sum_le_k(nums: List[int], k: int) -> int:
    l = 0
    cur_sum = 0
    max_len = 0

    for r, x in enumerate(nums):
        cur_sum += x
        while cur_sum > k and l <= r:
            cur_sum -= nums[l]
            l += 1
        if cur_sum <= k:
            max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(longest_subarray_sum_le_k(nums, k))