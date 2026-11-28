from typing import List

class TreeAncestor:
    def __init__(self, n: int, parent: List[int]):
        self.LOG = 20
        self.up = [[-1] * self.LOG for _ in range(n)]
        for i in range(n):
            self.up[i][0] = parent[i]

        for j in range(1, self.LOG):
            for i in range(n):
                if self.up[i][j - 1] != -1:
                    self.up[i][j] = self.up[self.up[i][j - 1]][j - 1]

    def getKthAncestor(self, node: int, k: int) -> int:
        for j in range(self.LOG):
            # If current bit is set, multiply base into result
            if (k >> j) & 1:
                node = self.up[node][j]
                if node == -1:
                    break
        return node