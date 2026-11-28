# problem title : Beautiful Arrangement
# Solve the stated task using standard input and standard output.
class Solution:
    def countArrangement(self, n: int) -> int:
        visited = [False] * (n + 1)

        def backtrack(pos: int) -> int:
            if pos > n:
                return 1
            count = 0
            for i in range(1, n + 1):
                if not visited[i] and (pos % i == 0 or i % pos == 0):
                    visited[i] = True
                    count += backtrack(pos + 1)
                    visited[i] = False
            return count

        return backtrack(1)
