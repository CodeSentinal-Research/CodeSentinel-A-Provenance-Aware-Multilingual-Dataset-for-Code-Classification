
from typing import List

class Solution:
    def buildPrefix(self, arr: List[int]) -> List[int]:
        prefix = [0]
        for x in arr:
            prefix.append(prefix[-1] + x)
        return prefix

    def query(self, prefix: List[int], l: int, r: int) -> int:
        return prefix[r + 1] - prefix[l]
