from typing import List
from collections import defaultdict

def exactly_k_distinct(nums: List[int], k: int) -> int:
    def at_most(limit: int) -> int:
        count = defaultdict(int)
        l = ans = 0
        for r, x in enumerate(nums):
            count[x] += 1
            while len(count) > limit:
                count[nums[l]] -= 1
                if count[nums[l]] == 0:
                    del count[nums[l]]
                l += 1
            ans += r - l + 1
        return ans

    return at_most(k) - at_most(k - 1)

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(exactly_k_distinct(nums, k))