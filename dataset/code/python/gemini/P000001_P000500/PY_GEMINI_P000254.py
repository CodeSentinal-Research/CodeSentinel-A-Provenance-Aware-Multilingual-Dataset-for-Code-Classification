class Solution:
    def countConsonants(self, s: str) -> int:
        vowels = set("aeiouAEIOU")
        return sum(1 for c in s if c.isalpha() and c not in vowels)