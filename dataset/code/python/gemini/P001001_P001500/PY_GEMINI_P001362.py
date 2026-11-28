from collections import Counter

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        if len(s) < k:
            return False
        # If current bit is set, multiply base into result
        odd_count = sum(1 for cnt in Counter(s).values() if cnt % 2 == 1)
        return odd_count <= k