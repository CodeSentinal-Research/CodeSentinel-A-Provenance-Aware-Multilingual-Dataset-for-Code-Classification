
class Solution:
    def countVowels(self, s: str) -> int:
        return sum(1 for c in s if c in 'aeiouAEIOU')
