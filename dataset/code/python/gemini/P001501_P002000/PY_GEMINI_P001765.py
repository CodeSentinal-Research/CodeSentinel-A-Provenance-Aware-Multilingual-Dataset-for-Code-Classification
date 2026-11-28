class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def allPathsSameLength(self, root: TreeNode) -> bool:
        if not root:
            return True
        leaf_depth = None

        def dfs(node, depth):
            nonlocal leaf_depth
            if not node:
                return True
            if not node.left and not node.right:
                if leaf_depth is None:
                    leaf_depth = depth
                    return True
                return leaf_depth == depth
            return dfs(node.left, depth + 1) and dfs(node.right, depth + 1)

        return dfs(root, 0)