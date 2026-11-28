class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def checkLeavesSameLevel(self, root: TreeNode) -> bool:
        leaf_level = None

        def dfs(node, level):
            nonlocal leaf_level
            if not node:
                return True
            if not node.left and not node.right:
                if leaf_level is None:
                    leaf_level = level
                    return True
                return leaf_level == level
            return dfs(node.left, level + 1) and dfs(node.right, level + 1)

        return dfs(root, 0)