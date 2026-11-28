# problem title : Rearrange Array Elements by Sign
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [0] * n
        pos, neg = 0, 1

        for x in nums:
            if x > 0:
                res[pos] = x
                pos += 2
            else:
                res[neg] = x
                neg += 2

        return res
