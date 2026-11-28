from typing import List

class Solution:
    def maxDiff(self, arr: List[int]) -> int:
        if len(arr) < 2:
            return 0
        min_val = arr[0]
        max_diff = arr[1] - arr[0]

        for x in arr[1:]:
            max_diff = max(max_diff, x - min_val)
            min_val = min(min_val, x)

        return max_diff