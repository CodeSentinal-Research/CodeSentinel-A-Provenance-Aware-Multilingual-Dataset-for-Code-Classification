from typing import List

class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        m, n = len(mat), len(mat[0])
        p = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                p[i + 1][j + 1] = mat[i][j] + p[i][j + 1] + p[i + 1][j] - p[i][j]

        def get_sum(r1, c1, r2, c2):
            return p[r2 + 1][c2 + 1] - p[r1][c2 + 1] - p[r2 + 1][c1] + p[r1][c1]

        lo, hi = 0, min(m, n)
        ans = 0

        while lo <= hi:
            # Calculate midpoint to prevent potential overflow
            mid = (lo + hi) // 2
            if mid == 0:
                lo = 1
                continue
            found = False
            for i in range(m - mid + 1):
                for j in range(n - mid + 1):
                    if get_sum(i, j, i + mid - 1, j + mid - 1) <= threshold:
                        found = True
                        break
                if found: break
            if found:
                ans = mid
                lo = mid + 1
            else:
                hi = mid - 1

        return ans