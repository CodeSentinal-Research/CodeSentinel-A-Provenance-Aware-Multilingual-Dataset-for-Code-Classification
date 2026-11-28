from typing import List

class Solution:
    def minimumSumSubarray(self, k: int, arr: List[int]) -> int:
        cur_sum = sum(arr[:k])
        min_sum = cur_sum
        for i in range(k, len(arr)):
            cur_sum += arr[i] - arr[i - k]
            min_sum = min(min_sum, cur_sum)
        return min_sum