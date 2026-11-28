from typing import List
from collections import defaultdict

def at_most_k_distinct(nums: List[int], k: int) -> int:
    count = defaultdict(int)
    l = 0
    ans = 0

    for r, x in enumerate(nums):
        count[x] += 1
        while len(count) > k:
            count[nums[l]] -= 1
            if count[nums[l]] == 0:
                del count[nums[l]]
            l += 1
        ans += r - l + 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(at_most_k_distinct(nums, k))