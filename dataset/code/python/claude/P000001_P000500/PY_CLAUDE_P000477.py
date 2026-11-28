
from typing import List

class Solution:
    def rotate(self, arr: List[int], k: int) -> List[int]:
        n = len(arr)
        k %= n
        arr[:] = arr[-k:] + arr[:-k]
        return arr
