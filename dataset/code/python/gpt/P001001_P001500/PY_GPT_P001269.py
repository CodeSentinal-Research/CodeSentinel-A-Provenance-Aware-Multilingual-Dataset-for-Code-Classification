# problem title : Divide Array into Sets of K Consecutive Numbers
# Solve the stated task using standard input and standard output.
from typing import List
from collections import Counter

class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        if len(nums) % k != 0:
            return False
        count = Counter(nums)
        for x in sorted(nums):
            if count[x] > 0:
                freq = count[x]
                for i in range(k):
                    if count[x + i] < freq:
                        return False
                    count[x + i] -= freq
        return True
