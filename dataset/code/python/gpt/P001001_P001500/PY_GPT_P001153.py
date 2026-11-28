# problem title : Count Palindromic Substrings
# Solve the stated task using standard input and standard output.
class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        def expand(l: int, r: int):
            nonlocal count
            while l >= 0 and r < len(s) and s[l] == s[r]:
                count += 1
                l -= 1
                r += 1

        for i in range(len(s)):
            expand(i, i)
            expand(i, i + 1)
        return count
