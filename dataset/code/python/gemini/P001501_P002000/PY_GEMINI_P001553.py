from typing import List
from collections import defaultdict

def longest_subarray_at_most_k_distinct(nums: List[int], k: int) -> int:
    count = defaultdict(int)
    l = max_len = 0

    for r, x in enumerate(nums):
        count[x] += 1
        while len(count) > k:
            count[nums[l]] -= 1
            if count[nums[l]] == 0:
                del count[nums[l]]
            l += 1
        max_len = max(max_len, r - l + 1)

    return max_len

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(longest_subarray_at_most_k_distinct(nums, k))