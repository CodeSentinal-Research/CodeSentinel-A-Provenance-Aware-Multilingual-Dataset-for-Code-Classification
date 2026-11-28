from typing import List

class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        score = 0
        seen = {}
        ans = 0

        for i, h in enumerate(hours):
            score += 1 if h > 8 else -1
            if score > 0:
                ans = i + 1
            else:
                if score not in seen:
                    seen[score] = i
                if score - 1 in seen:
                    ans = max(ans, i - seen[score - 1])

        return ans