# problem title : Count Lexicographically Sorted Vowel Strings
# Solve the stated task using standard input and standard output.
class Solution:
    def countVowelStrings(self, n: int) -> int:
        return (n + 4) * (n + 3) * (n + 2) * (n + 1) // 24
