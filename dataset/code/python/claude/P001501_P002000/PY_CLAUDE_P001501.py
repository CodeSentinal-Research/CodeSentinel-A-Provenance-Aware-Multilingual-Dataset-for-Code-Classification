
from typing import List, Tuple

class Solution:
    def twoPointer(self, arr: List[int], target: int) -> Tuple[int, int]:
        lo, hi = 0, len(arr) - 1
        while lo < hi:
            s = arr[lo] + arr[hi]
            if s == target:
                return lo, hi
            elif s < target:
                lo += 1
            else:
                hi -= 1
        return -1, -1
