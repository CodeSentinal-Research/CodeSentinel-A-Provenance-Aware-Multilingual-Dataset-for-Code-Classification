from typing import List
from collections import defaultdict

def count_distinct_windows(nums: List[int], k: int) -> int:
    if len(nums) < k:
        return 0
    count = defaultdict(int)
    for x in nums[:k]:
        count[x] += 1
    ans = 1 if len(count) == k else 0

    for i in range(k, len(nums)):
        count[nums[i]] += 1
        count[nums[i - k]] -= 1
        if count[nums[i - k]] == 0:
            del count[nums[i - k]]
        if len(count) == k:
            ans += 1

    return ans

if __name__ == '__main__':
    n, k = map(int, input().split())
    nums = list(map(int, input().split()))
    print(count_distinct_windows(nums, k))