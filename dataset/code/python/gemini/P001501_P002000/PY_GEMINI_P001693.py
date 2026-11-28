class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestUnivaluePath(self, root: TreeNode) -> int:
        max_path = 0

        def dfs(node):
            nonlocal max_path
            if not node:
                return 0
            l_len = dfs(node.left)
            r_len = dfs(node.right)

            l_arrow = l_len + 1 if node.left and node.left.val == node.val else 0
            r_arrow = r_len + 1 if node.right and node.right.val == node.val else 0

            max_path = max(max_path, l_arrow + r_arrow)
            return max(l_arrow, r_arrow)

        dfs(root)
        return max_path