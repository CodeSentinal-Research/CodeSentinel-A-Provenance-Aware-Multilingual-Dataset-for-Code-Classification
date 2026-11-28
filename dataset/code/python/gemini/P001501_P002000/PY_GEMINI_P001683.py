class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def deepestLeftLeaf(self, root: TreeNode) -> int:
        max_depth = -1
        res = -1

        def dfs(node, depth, is_left):
            nonlocal max_depth, res
            if not node:
                return
            if is_left and not node.left and not node.right:
                if depth > max_depth:
                    max_depth = depth
                    res = node.val
            dfs(node.left, depth + 1, True)
            dfs(node.right, depth + 1, False)

        dfs(root, 0, False)
        return res