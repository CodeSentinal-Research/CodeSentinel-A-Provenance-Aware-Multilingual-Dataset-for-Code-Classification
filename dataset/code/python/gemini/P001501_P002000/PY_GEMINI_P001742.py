from typing import List

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def getLeavesRightToLeft(self, root: TreeNode) -> List[int]:
        res = []

        def dfs(node):
            if not node:
                return
            if not node.left and not node.right:
                res.append(node.val)
                return
            dfs(node.right)
            dfs(node.left)

        dfs(root)
        return res