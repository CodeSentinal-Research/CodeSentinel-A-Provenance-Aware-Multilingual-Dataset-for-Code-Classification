from collections import Counter

class Solution:
    def getFrequencies(self, s: str) -> dict:
        return dict(Counter(s))