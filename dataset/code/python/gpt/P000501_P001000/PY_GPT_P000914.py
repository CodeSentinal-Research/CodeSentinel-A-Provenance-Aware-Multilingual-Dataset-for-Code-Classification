# problem title : Count Unique Grid Paths
# Solve the stated task using standard input and standard output.
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # (m + n - 2) choose (m - 1)
        total = m + n - 2
        r = min(m - 1, n - 1)
        ans = 1
        for i in range(1, r + 1):
            ans = ans * (total - i + 1) // i
        return ans
