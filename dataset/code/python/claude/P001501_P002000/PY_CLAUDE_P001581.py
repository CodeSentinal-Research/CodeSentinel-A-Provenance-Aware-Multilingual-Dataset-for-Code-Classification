
from typing import List

class Solution:
    def slidingWindowSum(self, arr: List[int], k: int) -> List[int]:
        result = []
        s = sum(arr[:k])
        result.append(s)
        for i in range(k, len(arr)):
            s += arr[i] - arr[i - k]
            result.append(s)
        return result
