class Solution:
    def longestSemiRepetitiveSubstring(self, s: str) -> int:
        n = len(s)
        ans = 1
        l = 0
        last_repeat = 0

        for r in range(1, n):
            if s[r] == s[r - 1]:
                if last_repeat > 0:
                    l = last_repeat
                last_repeat = r
            ans = max(ans, r - l + 1)

        return ans