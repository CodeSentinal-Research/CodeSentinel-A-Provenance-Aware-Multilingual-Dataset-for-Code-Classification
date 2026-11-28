class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def nodeHeights(self, root: TreeNode) -> dict:
        heights = {}

        def dfs(node):
            if not node:
                return -1
            h = 1 + max(dfs(node.left), dfs(node.right))
            heights[node.val] = h
            return h

        dfs(root)
        return heights