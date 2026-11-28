class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = set("aeiou")
        cur_vowels = sum(1 for c in s[:k] if c in vowels)
        max_vowels = cur_vowels

        for i in range(k, len(s)):
            cur_vowels += (s[i] in vowels) - (s[i - k] in vowels)
            max_vowels = max(max_vowels, cur_vowels)

        return max_vowels