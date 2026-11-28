from typing import List

class Solution:
    def wordCount(self, startWords: List[str], targetWords: List[str]) -> int:
        seen = set()
        for w in startWords:
            mask = 0
            for c in w:
                mask |= (1 << (ord(c) - 97))
            seen.add(mask)

        ans = 0
        for w in targetWords:
            mask = 0
            for c in w:
                mask |= (1 << (ord(c) - 97))
            for c in w:
                if (mask ^ (1 << (ord(c) - 97))) in seen:
                    ans += 1
                    break

        return ans