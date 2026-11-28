from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def constructOBST(self, keys: List[int], freq: List[int]) -> TreeNode:
        n = len(keys)
        cost = [[0] * n for _ in range(n)]
        root_idx = [[0] * n for _ in range(n)]
        w = [[0] * n for _ in range(n)]

        for i in range(n):
            w[i][i] = freq[i]
            cost[i][i] = freq[i]
            root_idx[i][i] = i
            for j in range(i + 1, n):
                w[i][j] = w[i][j - 1] + freq[j]

        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                cost[i][j] = float('inf')
                for r in range(i, j + 1):
                    c = (cost[i][r - 1] if r > i else 0) + (cost[r + 1][j] if r < j else 0) + w[i][j]
                    if c < cost[i][j]:
                        cost[i][j] = c
                        root_idx[i][j] = r

        def build(i, j):
            if i > j:
                return None
            r = root_idx[i][j]
            node = TreeNode(keys[r])
            node.left = build(i, r - 1)
            node.right = build(r + 1, j)
            return node

        return build(0, n - 1)