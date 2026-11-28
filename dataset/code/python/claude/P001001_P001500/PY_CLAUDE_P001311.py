
class Solution:
    def totalNQueens(self, n: int) -> int:
        self.count = 0
        col, d1, d2 = set(), set(), set()

        def solve(row):
            if row == n:
                self.count += 1
                return
            for c in range(n):
                if c not in col and row - c not in d1 and row + c not in d2:
                    col.add(c); d1.add(row - c); d2.add(row + c)
                    solve(row + 1)
                    col.remove(c); d1.remove(row - c); d2.remove(row + c)

        solve(0)
        return self.count
