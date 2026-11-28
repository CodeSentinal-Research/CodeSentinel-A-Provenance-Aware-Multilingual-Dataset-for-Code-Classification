from typing import List

class Solution:
    def maxRepeating(self, arr: List[int], n: int, k: int) -> int:
        for i in range(n):
            arr[arr[i] % k] += k

        max_val = arr[0]
        result = 0
        for i in range(1, k):
            if arr[i] > max_val:
                max_val = arr[i]
                result = i

        return result