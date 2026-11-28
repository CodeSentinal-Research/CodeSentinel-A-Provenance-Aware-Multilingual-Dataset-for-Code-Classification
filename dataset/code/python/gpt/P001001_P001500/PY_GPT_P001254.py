# problem title : Largest Number Formation
# Solve the stated task using standard input and standard output.
import functools
from typing import List

class Solution:
    def largestNumber(self, nums: List[int]) -> str:
        strs = list(map(str, nums))
        def cmp(a, b):
            if a + b > b + a:
                return -1
            elif a + b < b + a:
                return 1
            return 0

        strs.sort(key=functools.cmp_to_key(cmp))
        ans = "".join(strs)
        return "0" if ans[0] == "0" else ans
