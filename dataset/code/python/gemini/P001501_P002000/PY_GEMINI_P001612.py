from typing import List

class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        total = sum(arr)
        if total % 3 != 0:
            return False

        target = total // 3
        cur_sum = count = 0

        for x in arr:
            cur_sum += x
            if cur_sum == target:
                count += 1
                cur_sum = 0

        return count >= 3