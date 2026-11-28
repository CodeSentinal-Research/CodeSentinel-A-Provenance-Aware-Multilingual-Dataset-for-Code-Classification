from typing import List

def longest_binary_subarray_k_zeros(nums: List[int], k: int) -> int:
    l = zeros = max_len = 0

    for r, x in enumerate(nums):
        if x == 0:
            zeros += 1
        while zeros > k:
            if nums[l] == 0:
                zeros -= 1
            l += 1
        max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(longest_binary_subarray_k_zeros(nums, k))