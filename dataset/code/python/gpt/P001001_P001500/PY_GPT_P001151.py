# problem title : Longest Palindromic Substring
# Solve the stated task using standard input and standard output.
class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        start, max_len = 0, 1

        def expand(l: int, r: int):
            nonlocal start, max_len
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if r - l + 1 > max_len:
                    start = l
                    max_len = r - l + 1
                l -= 1
                r += 1

        for i in range(len(s)):
            expand(i, i)
            expand(i, i + 1)
        return s[start:start + max_len]
