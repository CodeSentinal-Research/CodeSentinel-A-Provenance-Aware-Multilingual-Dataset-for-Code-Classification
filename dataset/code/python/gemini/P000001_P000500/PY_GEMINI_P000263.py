from collections import Counter

class Solution:
    def lastNonRepeatingCharacter(self, s: str) -> str:
        freq = Counter(s)
        for c in reversed(s):
            if freq[c] == 1:
                return c
        return '$'