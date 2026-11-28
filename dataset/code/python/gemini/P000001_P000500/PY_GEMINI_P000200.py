from typing import List

class Solution:
    def twoOddNum(self, arr: List[int], n: int) -> List[int]:
        xor_all = 0
        for x in arr:
            xor_all ^= x

        diff_bit = xor_all & (-xor_all)
        x = y = 0
        for val in arr:
            if val & diff_bit:
                x ^= val
            else:
                y ^= val

        return [max(x, y), min(x, y)]