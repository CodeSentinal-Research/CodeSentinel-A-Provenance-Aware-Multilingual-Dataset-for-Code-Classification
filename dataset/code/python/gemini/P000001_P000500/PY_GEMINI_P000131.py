from typing import List

class Solution:
    def leaders(self, arr: List[int]) -> List[int]:
        res = []
        max_from_right = float('-inf')
        for x in reversed(arr):
            if x >= max_from_right:
                res.append(x)
                max_from_right = x
        return res[::-1]