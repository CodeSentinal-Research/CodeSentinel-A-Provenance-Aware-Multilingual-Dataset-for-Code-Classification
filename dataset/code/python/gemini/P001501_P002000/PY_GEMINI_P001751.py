class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodesWithKDescendants(self, root: TreeNode, k: int) -> int:
        ans = 0

        def dfs(node):
            nonlocal ans
            if not node:
                return 0
            desc = dfs(node.left) + dfs(node.right)
            if desc == k:
                ans += 1
            return desc + 1

        dfs(root)
        return ans