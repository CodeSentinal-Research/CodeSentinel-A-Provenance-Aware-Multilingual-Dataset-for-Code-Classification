from typing import List

class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        seen = {0: -1}
        prefix = 0

        for i, x in enumerate(nums):
            prefix = (prefix + x) % k
            if prefix in seen:
                if i - seen[prefix] >= 2:
                    return True
            else:
                seen[prefix] = i

        return False