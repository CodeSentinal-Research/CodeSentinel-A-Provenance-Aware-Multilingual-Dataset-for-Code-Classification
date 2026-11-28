from typing import List
import heapq

class Solution:
    def maximumProduct(self, nums: List[int], k: int) -> int:
        MOD = 10**9 + 7
        heapq.heapify(nums)
        for _ in range(k):
            heapq.heappush(nums, heapq.heappop(nums) + 1)

        res = 1
        for x in nums:
            res = (res * x) % MOD
        return res