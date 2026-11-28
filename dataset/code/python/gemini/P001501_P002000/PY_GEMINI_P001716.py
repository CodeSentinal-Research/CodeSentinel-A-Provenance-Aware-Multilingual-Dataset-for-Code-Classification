class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestLeaf(self, root: TreeNode) -> int:
        min_depth = float('inf')
        res = -1

        def dfs(node, depth):
            nonlocal min_depth, res
            if not node:
                return
            if not node.left and not node.right:
                if depth < min_depth:
                    min_depth = depth
                    res = node.val
                return
            dfs(node.left, depth + 1)
            dfs(node.right, depth + 1)

        dfs(root, 1)
        return res