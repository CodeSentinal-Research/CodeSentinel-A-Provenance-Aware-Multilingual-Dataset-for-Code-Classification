
class Solution:
    def checkVowelOrConsonant(self, c: str) -> str:
        if not c.isalpha():
            return "Neither"
        if c.lower() in "aeiou":
            return "Vowel"
        return "Consonant"
