class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countPathsKEdges(self, root: TreeNode, k: int) -> int:
        def dfs(node, edges):
            if not node:
                return 0
            if not node.left and not node.right:
                return 1 if edges == k else 0
            return dfs(node.left, edges + 1) + dfs(node.right, edges + 1)

        return dfs(root, 0)