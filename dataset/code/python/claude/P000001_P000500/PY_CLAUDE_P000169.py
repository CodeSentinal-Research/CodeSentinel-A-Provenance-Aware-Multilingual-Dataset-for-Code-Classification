
from typing import List, Optional

class Solution:
    def firstRepeating(self, nums: List[int]) -> Optional[int]:
        seen = set()
        for x in nums:
            if x in seen: return x
            seen.add(x)
        return None
