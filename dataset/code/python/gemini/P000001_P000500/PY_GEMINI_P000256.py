class Solution:
    def removeConsonants(self, s: str) -> str:
        vowels = set("aeiouAEIOU")
        return "".join(c for c in s if not c.isalpha() or c in vowels)