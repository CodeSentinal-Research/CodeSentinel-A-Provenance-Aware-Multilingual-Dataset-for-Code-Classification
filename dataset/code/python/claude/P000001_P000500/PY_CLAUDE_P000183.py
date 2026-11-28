
from typing import List
from collections import defaultdict

class Solution:
    def countDistinct(self, nums: List[int], k: int) -> List[int]:
        freq = defaultdict(int)
        res = []
        for i in range(len(nums)):
            freq[nums[i]] += 1
            if i >= k:
                freq[nums[i-k]] -= 1
                if freq[nums[i-k]] == 0:
                    del freq[nums[i-k]]
            if i >= k - 1:
                res.append(len(freq))
        return res
