from typing import List

class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n = len(grid)
        parent = list(range(4 * n * n))
        def find(i):
            if parent[i] == i: return i
            parent[i] = find(parent[i])
            return parent[i]

        def union(i, j):
            ri, rj = find(i), find(j)
            if ri != rj:
                parent[ri] = rj

        for r in range(n):
            for c in range(n):
                root = 4 * (r * n + c)
                val = grid[r][c]
                if val != '/':
                    union(root + 0, root + 1)
                    union(root + 2, root + 3)
                if val != '\\':
                    union(root + 0, root + 3)
                    union(root + 1, root + 2)

                # Connect with neighbors
                if r + 1 < n:
                    union(root + 2, 4 * ((r + 1) * n + c) + 0)
                if c + 1 < n:
                    union(root + 1, 4 * (r * n + c + 1) + 3)

        return sum(1 for i in range(4 * n * n) if find(i) == i)