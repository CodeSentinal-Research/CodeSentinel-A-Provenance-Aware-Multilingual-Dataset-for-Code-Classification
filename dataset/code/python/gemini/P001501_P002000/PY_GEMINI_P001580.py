from typing import List

def longest_subarray_at_most_k_odds(nums: List[int], k: int) -> int:
    l = odds = max_len = 0

    for r, x in enumerate(nums):
        if x % 2 != 0:
            odds += 1
        while odds > k:
            if nums[l] % 2 != 0:
                odds -= 1
            l += 1
        max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(longest_subarray_at_most_k_odds(nums, k))