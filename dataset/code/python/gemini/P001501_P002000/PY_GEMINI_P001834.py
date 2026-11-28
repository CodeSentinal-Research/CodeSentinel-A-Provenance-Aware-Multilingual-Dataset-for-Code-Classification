class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def isDeadEnd(self, root: TreeNode) -> bool:
        def dfs(node, low, high):
            if not node:
                return False
            if low == high:
                return True
            return dfs(node.left, low, node.val - 1) or dfs(node.right, node.val + 1, high)

        return dfs(root, 1, float('inf'))