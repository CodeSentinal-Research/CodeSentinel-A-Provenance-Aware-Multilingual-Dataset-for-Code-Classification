from collections import defaultdict

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def diagonalTraversal(self, root: TreeNode) -> list:
        diag_map = defaultdict(list)

        def dfs(node, d):
            if not node:
                return
            diag_map[d].append(node.val)
            dfs(node.left, d + 1)
            dfs(node.right, d)

        dfs(root, 0)
        res = []
        for d in sorted(diag_map.keys()):
            res.extend(diag_map[d])
        return res