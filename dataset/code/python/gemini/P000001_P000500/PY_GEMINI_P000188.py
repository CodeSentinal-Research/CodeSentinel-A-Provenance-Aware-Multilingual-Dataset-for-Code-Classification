from typing import List

class Solution:
    def subarraySum(self, arr: List[int], target: int) -> List[int]:
        l = 0
        cur_sum = 0
        for r, x in enumerate(arr):
            cur_sum += x
            while cur_sum > target and l < r:
                cur_sum -= arr[l]
                l += 1
            if cur_sum == target:
                return [l + 1, r + 1]
        return [-1]