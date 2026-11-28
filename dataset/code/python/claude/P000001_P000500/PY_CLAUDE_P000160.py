
from typing import List, Optional, Tuple

class Solution:
    def findPair(self, nums: List[int], target: int) -> Optional[Tuple[int, int]]:
        seen = set()
        for x in nums:
            if target - x in seen:
                return (target - x, x)
            seen.add(x)
        return None
