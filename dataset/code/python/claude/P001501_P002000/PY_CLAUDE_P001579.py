
from typing import List

class Solution:
    def maxSlidingWindowSum(self, arr: List[int], k: int) -> int:
        s = sum(arr[:k])
        max_sum = s
        for i in range(k, len(arr)):
            s += arr[i] - arr[i - k]
            max_sum = max(max_sum, s)
        return max_sum
