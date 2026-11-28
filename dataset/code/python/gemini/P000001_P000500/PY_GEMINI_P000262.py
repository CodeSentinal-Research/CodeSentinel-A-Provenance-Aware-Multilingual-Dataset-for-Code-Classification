from collections import Counter

class Solution:
    def nonrepeatingCharacter(self, s: str) -> str:
        freq = Counter(s)
        for c in s:
            if freq[c] == 1:
                return c
        return '$'