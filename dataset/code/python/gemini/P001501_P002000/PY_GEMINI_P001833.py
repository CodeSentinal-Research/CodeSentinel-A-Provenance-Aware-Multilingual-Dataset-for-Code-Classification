class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countDeadEnds(self, root: TreeNode) -> int:
        count = 0

        def dfs(node, low, high):
            nonlocal count
            if not node:
                return
            if low == high:
                count += 1
                return
            dfs(node.left, low, node.val - 1)
            dfs(node.right, node.val + 1, high)

        dfs(root, 1, float('inf'))
        return count