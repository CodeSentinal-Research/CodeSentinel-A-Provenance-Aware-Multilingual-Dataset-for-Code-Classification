from typing import List

class Solution:
    def maximumSumSubarray(self, k: int, arr: List[int]) -> int:
        cur_sum = sum(arr[:k])
        max_sum = cur_sum
        for i in range(k, len(arr)):
            cur_sum += arr[i] - arr[i - k]
            max_sum = max(max_sum, cur_sum)
        return max_sum