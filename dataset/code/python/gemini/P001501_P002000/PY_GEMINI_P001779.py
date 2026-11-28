class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def longestIncreasingPath(self, root: TreeNode) -> int:
        if not root:
            return 0
        max_len = 0

        def dfs(node, parent_val, cur_len):
            nonlocal max_len
            if not node:
                return
            if parent_val is None or node.val > parent_val:
                cur_len += 1
            else:
                cur_len = 1
            max_len = max(max_len, cur_len)
            dfs(node.left, node.val, cur_len)
            dfs(node.right, node.val, cur_len)

        dfs(root, None, 0)
        return max_len