# problem title : Palindrome Partitioning II
# Solve the stated task using standard input and standard output.
class Solution:
    def minCut(self, s: str) -> int:
        n = len(s)
        cuts = list(range(n))
        is_pal = [[False] * n for _ in range(n)]

        for i in range(n):
            for l, r in [(i, i), (i, i + 1)]:
                while l >= 0 and r < n and s[l] == s[r]:
                    cuts[r] = 0 if l == 0 else min(cuts[r], cuts[l - 1] + 1)
                    l -= 1
                    r += 1

        return cuts[n - 1]
