# problem title : Check Arithmetic Subarrays
# Solve the stated task using standard input and standard output.
from typing import List

class Solution:
    def checkArithmeticSubarrays(self, nums: List[int], l: List[int], r: List[int]) -> List[bool]:
        res = []
        for left, right in zip(l, r):
            sub = sorted(nums[left:right + 1])
            diff = sub[1] - sub[0]
            is_arith = all(sub[i] - sub[i - 1] == diff for i in range(2, len(sub)))
            res.append(is_arith)
        return res
